ifeq ($(strip $(MICROKIT_SDK)),)
$(error MICROKIT_SDK must be specified)
endif

BUILD_DIR ?= build
# By default we make a debug build so that the client debug prints can be seen.
MICROKIT_CONFIG ?= debug

QEMU := qemu-system-aarch64

CC := clang
LD := ld.lld
AR := llvm-ar
RANLIB := llvm-ranlib

MICROKIT_TOOL ?= $(MICROKIT_SDK)/bin/microkit

CFLAGS := -mcpu=$(CPU) \
	-mstrict-align \
	-nostdlib \
	-ffreestanding \
	-g3 \
	-O3 \
	-Wall -Wno-unused-function -Werror -Wno-unused-command-line-argument \
	-target aarch64-none-elf \
	-I$(BOARD_DIR)/include
LDFLAGS := -L$(BOARD_DIR)/lib
LIBS := --start-group -lmicrokit -Tmicrokit.ld --end-group


PRINTF_OBJS := printf.o util.o
PERIODIC_DISPATCHER_OBJS := $(PRINTF_OBJS) periodic_dispatcher.o
PRODUCER_OBJS := $(PRINTF_OBJS) producer.o
CONSUMER_OBJS := $(PRINTF_OBJS) consumer.o
END_OF_SCHEDULE_PING_OBJS := $(PRINTF_OBJS) end_of_schedule_ping.o


SYSTEM_FILE := ${TOP}/dataport.system

IMAGES := periodic_dispatcher.elf producer.elf consumer.elf end_of_schedule_ping.elf
IMAGE_FILE_DATAPORT = dataport.img
IMAGE_FILE = loader.img
REPORT_FILE = /report.txt

all: $(IMAGE_FILE)
	CHECK_FLAGS_BOARD_MD5:=.board_cflags-$(shell echo -- ${CFLAGS} ${BOARD} ${MICROKIT_CONFIG} | shasum | sed 's/ *-//')

${CHECK_FLAGS_BOARD_MD5}:
	-rm -f .board_cflags-*
	touch $@

%.o: ${TOP}/%.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

printf.o: ${TOP}/include/printf.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

util.o: ${TOP}/include/util.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

periodic_dispatcher.elf: $(PERIODIC_DISPATCHER_OBJS)
	$(LD) $(LDFLAGS) $^ $(LIBS) -o $@

producer.elf: $(PRODUCER_OBJS)
	$(LD) $(LDFLAGS) $^ $(LIBS) -o $@

consumer.elf: $(CONSUMER_OBJS)
	$(LD) $(LDFLAGS) $^ $(LIBS) -o $@

end_of_schedule_ping.elf: $(END_OF_SCHEDULE_PING_OBJS)
	$(LD) $(LDFLAGS) $^ $(LIBS) -o $@

$(IMAGE_FILE): $(IMAGES) $(SYSTEM_FILE)
	$(MICROKIT_TOOL) $(SYSTEM_FILE) --search-path $(BUILD_DIR) --board $(MICROKIT_BOARD) --config $(MICROKIT_CONFIG) -o $(IMAGE_FILE) -r $(REPORT_FILE)


qemu: $(IMAGE_FILE)
	$(QEMU) -machine virt,virtualization=on \
			-cpu cortex-a53 \
			-serial mon:stdio \
			-device loader,file=$(IMAGE_FILE),addr=0x70000000,cpu-num=0 \
			-m size=2G \
			-nographic

clean::
	rm -f procuder.o consumer.o
clobber:: clean
	rm -f producer.elf consumer.elf ${IMAGE_FILE} ${REPORT_FILE}
