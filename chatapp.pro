LIBS += \
       -lboost_system\
       -lpthread\
       -lboost_thread\

SOURCES += \
    src/main.cpp \
    src/server.cpp \
    src/client.cpp

HEADERS += \
    src/master_header.hpp \
    src/chat_message.hpp

