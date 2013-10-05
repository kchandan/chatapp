LIBS += \
       -lboost_system\
       -lpthread\
       -lboost_thread\

SOURCES += \
    server/server.cpp \
    server/server_ui.cpp

HEADERS += \
    inc/chat_message.hpp \
    server/chat_message.hpp

