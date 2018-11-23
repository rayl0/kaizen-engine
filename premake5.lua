workspace "Hazel"
    location "build"
	
	platforms 
	{
		"x64",
		"x32"
	}
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}


dofile "external/external.lua"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Sandbox"
	location "build/Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/source/**.h",
		"%{prj.name}/source/**.cc"
	}

	includedirs
	{
		"%{prj.name}/source",
		"external/nlohmann/include"
	}

	links
	{
		"SDL2main",
		"SDL2",
		"SDL2_image"
	}

	filter "platforms:*32"
		architecture "x32"

	filter "platforms:*64"
		architecture "x64"

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.17134.0"

		defines
		{
			"KZ_PLATFORM_WINDOWS"
		}

	filter "system:linux"
		staticruntime "On"
		buildoptions {
			"-fPIC",
			"-no-canonical-prefixes",
			"-Wa,--noexecstack",
			"-fstack-protector",
			"-ffunction-sections",
			"-Wno-psabi",
			"-Wunused-value",
			"-Wundef",
			"-msse2"
		}
		linkoptions {
			"-Wl,--gc-sections"
		}

	filter "configurations:Debug"
		defines "KZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "KZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "KZ_DIST"
		optimize "On"

	filter {}
