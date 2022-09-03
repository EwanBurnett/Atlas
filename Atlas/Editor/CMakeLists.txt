
project(Atlas-Editor VERSION 0.1.0 LANGUAGES CSharp)

FILE(GLOB_RECURSE SOURCE_CS_FILES "*.cs") 
FILE(GLOB_RECURSE SOURCE_XAML_FILES "*.axaml") 
FILE(GLOB_RECURSE SOURCE_AXAML_CS_FILES "*.axaml.cs") 

add_executable(${PROJECT_NAME} ${SOURCE_CS_FILES} ${SOURCE_AXAML_FILES})



set_property(SOURCE App.xaml PROPERTY VS_XAML_TYPE "ApplicationDefinition")

set_property(TARGET Example PROPERTY VS_DOTNET_TARGET_FRAMEWORK_VERSION "v4.6.1")
set_property(TARGET Example PROPERTY WIN32_EXECUTABLE TRUE)

set_property(TARGET Example PROPERTY VS_DOTNET_REFERENCES
    "Microsoft.CSharp"
    "PresentationCore"
    "PresentationFramework"
    "System"                                                                                                                                     
    "System.Core"
    "System.Data"
    "System.Data.DataSetExtensions"
    "System.Net.Http"
    "System.Xaml"
    "System.Xml"
    "System.Xml.Linq"
    "WindowsBase")