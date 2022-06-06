idf_component_register(SRCS "src/tcp_client.c"
                        INCLUDE_DIRS include
                        REQUIRES
                        protocol_common
                        sht3x
                        sntp)