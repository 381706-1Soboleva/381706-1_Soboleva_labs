
file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
file(GLOB srcs "*.cpp") #Добавляем в переменную srcs все файлы с расширением .cpp


add_executable(${Test} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${PROJECT_NAME}, в него добавляются файлы из переменных ${srcs} и ${hdrs}

target_link_libraries(${Test} ${VectorLib} gtest )
target_link_libraries(${Test} ${MatrixLib} gtest )
target_link_libraries(${Test} ${StackLib} gtest )
target_link_libraries(${Test} ${MStackLib} gtest )
target_link_libraries(${Test} ${QueueLib} gtest )
target_link_libraries(${Test} ${ListLib} gtest )
target_link_libraries(${Test} ${ListMasLib} gtest )
target_link_libraries(${Test} ${StackListLib} gtest )
target_link_libraries(${Test} ${PolyLib} gtest )
target_link_libraries(${Test} ${ObrPolLib} gtest )

