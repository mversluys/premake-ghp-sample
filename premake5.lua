require 'ghp'
location 'build'

workspace 'sample-workspace'
        configurations { 'Debug', 'Release' }

filter { 'system:macosx' }
        buildoptions { '-std=c++11', '-stdlib=libc++' }
        linkoptions { '-std=c++11'}
filter { }

ghp.import('mversluys/asio', 'v1.10.6a')
ghp.import('mversluys/websocketpp', 'v0.6.0')

project 'sample-project'
        kind 'ConsoleApp'
        ghp.use('mversluys/asio')
        ghp.use('mversluys/websocketpp')
        language 'C++'
        files { 'main.cc' }
