cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME 381706-1_Soboleva_labs) #Создаем обычную локальную переменную с именем проекта

project(${PROJECT_NAME}) # Название проекта

set (Vector Vector) #Переменная с именем библиотеки
set (VectorLib VectorLib)
set (Test Test)
set (MatrixLib MatrixLib)
set (Matrix Matrix)
set (StackLib StackLib)
set (Stack Stack)
set (MStackLib MStackLib)
set (MStack MStack)
set (QueueLib QueueLib)
set (Queue Queue)
set (ListLib ListLib)
set (List List)





set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
   set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()



include_directories (
${CMAKE_CURRENT_SOURCE_DIR}/VectorLib
${CMAKE_CURRENT_SOURCE_DIR}/MatrixLib
${CMAKE_CURRENT_SOURCE_DIR}/StackLib
${CMAKE_CURRENT_SOURCE_DIR}/MStackLib
${CMAKE_CURRENT_SOURCE_DIR}/QueueLib
${CMAKE_CURRENT_SOURCE_DIR}/ListLib
${CMAKE_CURRENT_SOURCE_DIR}/gtest
) #чтобы не указывать полные пути до ашников





add_subdirectory(VectorLib)
add_subdirectory(Vector)
add_subdirectory(MatrixLib)
add_subdirectory(Matrix)
add_subdirectory(StackLib)
add_subdirectory(Stack)
add_subdirectory(MStackLib)
add_subdirectory(MStack)
add_subdirectory(QueueLib)
add_subdirectory(Queue)
add_subdirectory(ListLib)
add_subdirectory(List)
add_subdirectory(Test)
add_subdirectory(gtest)



#add_subdirectory(lib1) #Собираем проект в поддиректории lib1

#target_link_libraries(${PROJECT_NAME} ${MyLib1}) #Подключаем к проекту с именем ${PROJECT_NAME} библиотеку с именем ${MyLib1}
