##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=UVa-10305
ConfigurationName      :=Debug
WorkspacePath          := "D:\Programming\UVa-Practice"
ProjectPath            := "D:\Programming\UVa-Practice\UVa-10305"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Kamrul Hasan
Date                   :=21/01/2016
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=C:/LLVM/x64/bin/clang++.exe
SharedObjectLinkerName :=C:/LLVM/x64/bin/clang++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="UVa-10305.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            := $(IncludeSwitch)C:/TDM-GCC-64/lib/gcc/x86_64-w64-mingw32/5.1.0/include/c++ $(IncludeSwitch)C:/TDM-GCC-64/lib/gcc/x86_64-w64-mingw32/5.1.0/include/c++/x86_64-w64-mingw32 $(IncludeSwitch)C:/TDM-GCC-64/lib/gcc/x86_64-w64-mingw32/5.1.0/include/c++/backward $(IncludeSwitch)C:/TDM-GCC-64/lib/gcc/x86_64-w64-mingw32/5.1.0/include $(IncludeSwitch)C:/TDM-GCC-64/include $(IncludeSwitch)C:/TDM-GCC-64/lib/gcc/x86_64-w64-mingw32/5.1.0/include-fixed $(IncludeSwitch)C:/TDM-GCC-64/x86_64-w64-mingw32/include  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/LLVM/x64/bin/llvm-ar.exe rcu
CXX      := C:/LLVM/x64/bin/clang++.exe
CC       := C:/LLVM/x64/bin/clang.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/LLVM/x64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/UVa10305.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/UVa10305.cpp$(ObjectSuffix): UVa10305.cpp $(IntermediateDirectory)/UVa10305.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Programming/UVa-Practice/UVa-10305/UVa10305.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/UVa10305.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/UVa10305.cpp$(DependSuffix): UVa10305.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/UVa10305.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/UVa10305.cpp$(DependSuffix) -MM "UVa10305.cpp"

$(IntermediateDirectory)/UVa10305.cpp$(PreprocessSuffix): UVa10305.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/UVa10305.cpp$(PreprocessSuffix) "UVa10305.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


