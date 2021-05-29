#cmake_minimum_required(VERSION 3.9)
#project(main)
#
#set(CMAKE_CXX_STANDARD 14)
#
#find_package(cpprestsdk REQUIRED)
#
#add_executable(main
#        Discord_Virtuals.cpp
#        Discord.cpp Discord.h
#        Invite.cpp Invite.h
#        Guild.cpp Guild.h
#        Emoji.cpp Emoji.h
#        Embed.cpp Embed.h
#        Endpoints.cpp
#        Intents.cpp Intents.h
#        Member.cpp Member.h
#        Role.cpp Role.h
#        User.cpp User.h
#        Channel.cpp Channel.h
#        Message.cpp Message.h
#        Utilities.cpp Utilities.h
#        Ready.cpp Ready.h
#        Log.cpp Log.h
#        Voice.cpp Voice.h
#        main.cpp)
#
#target_link_libraries(main PRIVATE cpprestsdk::cpprest)
