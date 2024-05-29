-- [Update Libs] --
os.execute("git submodule update --remote");

-- ############### Generate Project ############### --
workspace "Maze-AI"  
-- [Base] --
    language "C++"   
    cppdialect "C++20"
    architecture "x86_64"
    location "Maze-AI"
	startproject "APP"
    objdir ("bin")

-- [Modes] --
configurations { "Debug", "Release" } 

-- [Globals] --
    includedirs "Maze-AI/Lib/Include"
    libdirs "Maze-AI/Lib/Lib"

-- [APP] --
project "APP"  
    files { "**.h", "**.cpp" } 
    location "Maze-AI/APP"
    links { "AI", "MAZE" }
    kind "consoleapp"  
-- [AppMode Debug]
    filter "configurations:Debug"
    defines { "CE_DEBUG" }
    symbols "On"
    optimize "Off"
    targetdir "Output/Debug" 
    debugdir "Output/Debug"
-- [AppMode Release]
    filter "configurations:Release"
    defines { "CE_RELEASE" }
    symbols "Off"
    optimize "On"
    targetdir "Output/Release" 
    debugdir "Output/Release"

-- [AI] --
project "AI"  
    files { "**.h", "**.cpp" } 
    location "Maze-AI/AI"
    kind "staticlib"
    -- [AppMode Debug]
    filter "configurations:Debug"
    defines { "CE_DEBUG" }
    symbols "On"
    optimize "Off"
    targetdir "Output/Debug" 
    debugdir "Output/Debug"
    -- [AppMode Release]
    filter "configurations:Release"
    defines { "CE_RELEASE" }
    symbols "Off"
    optimize "On"
    targetdir "Output/Release" 
    debugdir "Output/Release"

-- [MAZE] --
project "MAZE"  
    files { "**.h", "**.cpp" } 
    location "Maze-AI/MAZE"
    kind "staticlib"
    -- [AppMode Debug]
    filter "configurations:Debug"
    defines { "CE_DEBUG" }
    symbols "On"
    optimize "Off"
    targetdir "Output/Debug" 
    debugdir "Output/Debug"
    -- [AppMode Release]
    filter "configurations:Release"
    defines { "CE_RELEASE" }
    symbols "Off"
    optimize "On"
    targetdir "Output/Release" 
    debugdir "Output/Release"