# Do not edit this file as it will be overwritten if HAMR codegen is rerun

cmake_minimum_required(VERSION 3.8.2)

project (top_impl_Instance C)

add_definitions(-DCAMKES)

if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "(C|c?)lang")
  add_compile_options("$<$<CONFIG:Release>:-Oz>")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  add_compile_options(-fstack-usage)
  add_compile_options("$<$<CONFIG:Release>:-Os>")
endif()

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/types)

DeclareCAmkESComponent(producer_t_i_producer_producer
  SOURCES components/producer_t_i_producer_producer//src/producer.c components/producer_t_i_producer_producer/src/sb_producer_t_i.c
  INCLUDES components/producer_t_i_producer_producer/includes/ types/includes
)

DeclareCAmkESComponent(consumer_t_i_consumer_consumer
  SOURCES components/consumer_t_i_consumer_consumer//src/consumer.c components/consumer_t_i_consumer_consumer/src/sb_consumer_t_i.c
  INCLUDES components/consumer_t_i_consumer_consumer/includes/ types/includes
)

DeclareCAmkESRootserver(top_impl_Instance.camkes)
