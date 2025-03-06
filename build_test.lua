-- build_lib.lua
workspace "versis_gui"
   configurations { "Debug", "Release" }

project "versis_gui"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"
   includedirs { "./dep/include/", "./src/" }
   libdirs { "./dep/lib/", "./bin/Debug/" }
   links { "SDL2main", "SDL2", "lunomath" }
   files { "./sim/**.h", "./sim/**.hpp", "./sim/**.cpp" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
