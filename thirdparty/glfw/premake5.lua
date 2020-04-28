project "GLFW"
    kind "StaticLib"
    language "C"

    targetdir "bin/%{prj.name}-%{cfg.buildcfg}-%{cfg.architecture}/"
    objdir "obj/%{prj.name}-%{cfg.buildcfg}-%{cfg.architecture}/"

    files
    {
        "include/GLFW/glfw3.h",
        "include/GLFW/glfw3native.h",

        "src/glfw_config.h",
        "src/context.h",
        "src/init.c",
        "src/input.h",
        "src/monitor.c",
        "src/vulkan.c",
        "src/window.c"
    }

    filter "system:windows"
        systemversion "latest"
        staticruntime "On"

        files
        {
            "src/win32_init.c",
			"src/win32_joystick.c",
			"src/win32_monitor.c",
			"src/win32_time.c",
			"src/win32_thread.c",
			"src/win32_window.c",
			"src/wgl_context.c",
			"src/egl_context.c",
			"src/osmesa_context.c"
        }

        defines
        {
            "_GLFW_WIN32"
        }

    filter "system:macos"
        systemversion "latest"

        files
        {
            "src/cocoa_init.m",
            "src/cocoa_joystick.m",
            "src/cocoa_monitor.m",
            "src/cocoa_time.c",
            "src/cocoa_window.m",
        }

        defines
        {
            "_GLFW_COCOA"
        }
    
    filter "system:linux"
        systemversion "latest"
        pic "On"
        staticruntime "On"

        files
        {
            "src/x11_init.c",
			"src/x11_monitor.c",
			"src/x11_window.c",
			"src/xkb_unicode.c",
			"src/posix_time.c",
			"src/posix_thread.c",
			"src/glx_context.c",
			"src/egl_context.c",
			"src/osmesa_context.c",
			"src/linux_joystick.c"
        }

        defines
        {
            "_GLFW_X11"
        }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"

