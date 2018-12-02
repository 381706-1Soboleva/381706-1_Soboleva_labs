et(target ${MP2_TESTS}

file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
file(GLOB srcs "*.cpp") #Добавляем в переменную srcs все файлы с расширением .cpp


add_executable(${Test} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${PROJECT_NAME}, в него добавляются файлы из переменных ${srcs} и ${hdrs}

#target_link_libraries(${Test} ${VectorLib} gtest )
#target_link_libraries(${Test} ${MatrixLib} gtest )
target_link_libraries(${target} gtest ${MP2_LIBRARY})
