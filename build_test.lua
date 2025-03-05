-- build_lib.lua
workspace "test"
   configurations { "Debug", "Release" }

project "test"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"
   includedirs { "./dep/include/", "./eng/" }
   libdirs { "./dep/lib/", "./bin/Debug/" }
   links { "SDL2main", "SDL2", "lunomath" }
   files { "./test/**.h", "./test/**.hpp", "./test/**.cpp" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
