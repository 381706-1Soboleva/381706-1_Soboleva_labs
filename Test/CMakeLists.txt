set (target ${LAB_TESTS})

file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
file(GLOB srcs "*.cpp") #Добавляем в переменную srcs все файлы с расширением .cpp


add_executable(${target} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${PROJECT_NAME}, в него добавляются файлы из переменных ${srcs} и ${hdrs}

target_link_libraries(${target} ${VectorLib} gtest  )
target_link_libraries(${target} ${MatrixLib} gtest )
