workspace "YngEngine"
	architecture "x64"

	cpnfigurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "YngEngine"
	location "YngEngine"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"YNG_PLATFORM_WINDOWS" ,
			"YNG_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
	
	filter "configurations:Debug"
		defines "YNG_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "YNG_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "YNG_DIST"
		optimize "On"


		
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
		"YngEngine/src"
	}

	links
	{
		"YngEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"YNG_PLATFORM_WINDOWS" 
		}
	
	filter "configurations:Debug"
		defines "YNG_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "YNG_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "YNG_DIST"
		optimize "On"
