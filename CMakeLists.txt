cmake_minimum_required(VERSION 3.14)
project(NeuralNetProject)

set(CMAKE_CXX_STANDARD 14)

# אומר לקומפיילר איפה לחפש את קובצי ה-.h
include_directories(NeuralNet_Foundation)

# ---------------------------------------------------------
# טסט 1: בדיקת מטריצות (זה הטסט שעבדנו עליו הרגע!)
# ---------------------------------------------------------
add_executable(FirstTest
        NeuralNet_Foundation/FirstTest.cpp
        NeuralNet_Foundation/Matrix.cpp
)

# ---------------------------------------------------------
# טסט 2: בדיקת השכבה
# ---------------------------------------------------------
add_executable(LayerTest
        NeuralNet_Foundation/secondtest.cpp
        NeuralNet_Foundation/Matrix.cpp
        NeuralNet_Foundation/Layer.cpp
)

# ---------------------------------------------------------
# טסט 3: רשת הנוירונים המלאה (Network)
# ---------------------------------------------------------
# שים לב: חייב להיות כאן קובץ שמכיל int main() (למשל Network_Run.cpp)
# כרגע שמתי פה את Network.cpp וכל מה שהוא תלוי בו.
add_executable(NetworkTarget
        # NeuralNet_Foundation/Main_Network_Run.cpp  <-- תוסיף את הקובץ עם ה-main שלך כאן
        NeuralNet_Foundation/Network.cpp
        NeuralNet_Foundation/Layer.cpp
        NeuralNet_Foundation/Matrix.cpp
)

# (הערה: את MatrixTest הישן הורדתי כי נראה ש-FirstTest החליף אותו.
# אם אתה עדיין צריך את Main_Matrix_Run.cpp, פשוט תוסיף אותו במקום FirstTest.cpp)