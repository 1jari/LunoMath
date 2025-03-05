-- build_lib.lua
workspace "test"
   configurations { "Debug", "Release" }

project "test"
   kind "WindowedApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"
   includedirs "./dep/include/"
   libdirs "./dep/lib/"
   links { "SDL2main", "SDL2" }
   files { "./test/**.h", "./test/**.hpp", "./test/**.cpp" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
