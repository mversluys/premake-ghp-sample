require 'ghp'
ghp.consumer('mversluys/premake-ghp-sample')

location 'build'

workspace 'sample-workspace'
        configurations { 'Debug', 'Release' }

flags { 'C++11' }

ghp.environment = 'ghp_environment'

ghp.import('mversluys/asio', 'v1.10.6a')
ghp.import('mversluys/websocketpp', 'v0.6.0')

project 'sample-project'
        kind 'ConsoleApp'
        ghp.use('mversluys/asio')
        ghp.use('mversluys/websocketpp')
        language 'C++'
        files { 'main.cc' }
