@echo off
premake5 vs2022
msbuild lunomath.sln
msbuild test.sln