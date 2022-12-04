-- premake5.lua

workspace "Astronomy"
	architecture {"x86", "x64"}
	configurations { "Debug", "Release", "Dist"}


-- variables
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


project "Astronomy"jk
    location "Astronomy"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("obj/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs {
        "%{prj.name}/libs/spdlog/include"
    }


    filter "system:windows"
        staticruntime "On"
        systemversion "latest"

        defines {
            "ASTRO_PLATFORM_WINDOWS",
            "ASTRO_BUILD_DLL",
            "_WINDLL"
        }
        
        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }


    filter "configurations:Debug"
        defines { "ASTRO_DEBUG" }
        symbols "On"


    filter "configurations:Release"
        defines { "ASTRO_RELEASE" }
        optimize "On"


    filter "configurations:Dist"
        defines { "ASTRO_DIST" }
        optimize "On"



project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("obj/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs {
        "%{prj.name}/libs/spdlog/include",
        "Astronomy/src"
    }

    links {
        "Astronomy"
    }

    filter "system:windows"
        staticruntime "On"
        systemversion "latest"

        defines {
            "ASTRO_PLATFORM_WINDOWS",
        }


    filter "configurations:Debug"
        defines {"ASTRO_DEBUG"}
        symbols "On"


    filter "configurations:Release"
        defines {"ASTRO_RELEASE"}
        optimize "On"


    filter "configurations:Dist"
        defines {"ASTRO_DIST"}
        optimize "On"
