-- build_lib.lua
workspace "versis_gui"
   configurations { "Debug", "Release" }

project "versis_gui"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"
   
   includedirs { "./dep/include/", "./src/" }
   libdirs { "./dep/lib/", "./bin/Debug/" }

   links {     "Opengl32",
               "SDL2main",
               "SDL2", 
               "SDL2_ttf",
               "lunomath" }

   files {     "./sim/**.h", 
               "./sim/**.hpp",
               "./sim/**.cpp",
               "./dep/include/GL/glad.c"}

   defines { "IMGUI_IMPL_OPENGL_LOADER_GLEW" }
   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
