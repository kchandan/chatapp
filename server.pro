LIBS += \
       -lboost_system\
       -lpthread\
       -lboost_thread\

SOURCES += \
    server/server.cpp \
    server/server_ui.cpp

HEADERS += \
    inc/master_header.hpp \
    inc/chat_message.hpp

