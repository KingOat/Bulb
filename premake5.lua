workspace "Bulb"
	architecture "x64"

	configurations 
	{
		"Debug",
		"Release",
		"Dist"
	}

	startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


project "Bulb"
	location "Bulb"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}
	
	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
				"BLB_PLATFORM_WINDOWS",
				"BLB_BUILD_DLL"
		}

		postbuildcommands 
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "BLB_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BLB_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "BLB_DIST"
		symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Bulb/vendor/spdlog/include",
		"Bulb/src"
	}

	links 
	{
		"Bulb"
	}
	
	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
				"BLB_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "BLB_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BLB_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "BLB_DIST"
		symbols "On"