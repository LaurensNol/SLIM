workspace "Slim"
    architecture "x86_64"
    startproject "Playground"

    configurations { "Debug", "Release"}
    flags { "MultiProcessorCompile" }

libraries = {}
libraries["glad"]      = "thirdparty/glad"
libraries["glfw"]      = "thirdparty/glfw"
libraries["glm"]       = "thirdparty/glm"
libraries["imgui"]     = "thirdparty/imgui"
libraries["spdlog"]    = "thirdparty/spdlog"
libraries["stb_image"] = "thirdparty/stb_image"

group "Dependencies"
    include "/thirdparty/glad/"
    include "/thirdparty/glfw/"
    include "/thirdparty/imgui/"

 -- Slim
project "Slim"
    location "Slim"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir "bin/%{prj.name}-%{cfg.buildcfg}-%{cfg.architecture}/"
    objdir "obj/%{prj.name}-%{cfg.buildcfg}-%{cfg.architecture}/"

    pchheader "slimpch.h"
    pchsource "Slim/slimpch.cpp"

    files
    {
        "%{prj.name}/**.h",
        "%{prj.name}/**.cpp",

        "%{libraries.stb_image}/**.h",
        "%{libraries.stb_image}/**.cpp",

        "%{libraries.glm}/glm/**.hpp",
        "%{libraries.glm}/glm/**.inl"
    }

    defines
    {
        "GLFW_INCLUDE_NONE",
        "_CRT_SECURE_NO_WARNINGS"
    }

    includedirs
    {
        "%{prj.name}/",
        "%{libraries.glad}/include",
        "%{libraries.glfw}/include",
        "%{libraries.glm}",
        "%{libraries.imgui}",
        "%{libraries.spdlog}/include",
        "%{libraries.stb_image}/"
    }
    
    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"
        defines "_SLIM_PLATFORM_WINDOWS"

    filter "system:macosx"
        systemversion "latest"
        defines "_SLIM_PLATFORM_MACOS"

    filter "system:linux"
        systemversion "latest"
        defines "_SLIM_PLATFORM_LINUX"

    filter "configurations:Debug"
        defines "_SLIM_DEBUG"
        symbols "on"
        runtime "Debug"

    filter "configurations:Release"
        defines "_SLIM_RELEASE"
        optimize "on"
        runtime "Release"


        
 -- Playground
project "Playground"
    location "Playground"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir "bin/%{prj.name}-%{cfg.buildcfg}-%{cfg.architecture}/"
    objdir "obj/%{prj.name}-%{cfg.buildcfg}-%{cfg.architecture}/"

    files
    {
        "%{prj.name}/**.h",
        "%{prj.name}/**.cpp"
    }

    includedirs
    {
        "Slim/",
        "%{libraries.spdlog}/include",
        "%{libraries.glm}"
    }

    links
    {
        "Slim"
    }

    filter "system:windows"
        systemversion "latest"
        defines "_SLIM_PLATFORM_WINDOWS"

    filter "system:macosx"
        systemversion "latest"
        defines "_SLIM_PLATFORM_MACOS"

    filter "system:linux"
        systemversion "latest"
        defines "_SLIM_PLATFORM_LINUX"

    filter "configurations:Debug"
        defines "_SLIM_DEBUG"
        symbols "on"
        runtime "Debug"

    filter "configurations:Release"
        defines "_SLIM_RELEASE"
        optimize "on"
        runtime "Release"
