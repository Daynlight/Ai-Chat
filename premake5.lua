-- [Update Libs] --
os.execute("git submodule update --remote");

-- ############### Generate Project ############### --
workspace "Maze-AI"  
-- [Base] --
    language "C++"   
    cppdialect "C++20"
    architecture "x86_64"
    location "Maze-AI"
	startproject "App"
    objdir ("bin")

-- [Modes] --
configurations { "Debug", "Release" } 

-- [Globals] --
    includedirs "Maze-AI/Lib/Include"
    libdirs "Maze-AI/Lib/Lib"
    links {}

-- [APP] --
project "App"  
    files { "**.h", "**.cpp" } 
    location "Maze-AI/Code"

-- [AppMode Debug]
    filter "configurations:Debug"
    defines { "CE_DEBUG" }
    kind "consoleapp"  
    symbols "On"
    optimize "Off"
    targetdir "Output/Debug" 
    debugdir "Output/Debug"
-- [AppMode Release]
    filter "configurations:Release"
    defines { "CE_RELEASE" }
    kind "consoleapp"
    symbols "Off"
    optimize "On"
    targetdir "Output/Release" 
    debugdir "Output/Release"