project "ImGui"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"

    targetdir "bin/%{prj.name}-%{cfg.buildcfg}-%{cfg.architecture}/"
    objdir "obj/%{prj.name}-%{cfg.buildcfg}-%{cfg.architecture}/"

    files
    {
        "imconfig.h",
		"imgui.h",
		"imgui.cpp",
		"imgui_draw.cpp",
		"imgui_internal.h",
		"imgui_widgets.cpp",
		"imstb_rectpack.h",
		"imstb_textedit.h",
		"imstb_truetype.h",
		"imgui_demo.cpp"
    }

    filter "system:windows"
        systemversion "latest"
        staticruntime "On"

    filter "system:macosx"
        systemversion "latest"

    filter "system:linux"
        systemversion "latest"
        pic "On"
        staticruntime "On"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"