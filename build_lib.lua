-- build_lib.lua
workspace "lunomath"
   configurations { "Debug", "Release" }

project "lunomath"
   kind "StaticLib"
   language "C"
   targetdir "bin/%{cfg.buildcfg}"

   files { "./src/**.h", "./src/**.c" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"