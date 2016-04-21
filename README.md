V 1.*.* - Динамическая строка.Объект класса хранит строку текста и ее длину. 
Память выделяется динамически, ее размер соответствует длине текста, который надо сохранить.
При изменении длины строки осуществлять динамическое перераспределение памяти.
Реализованы основные методы работы с объектами.

V 2.*.* -Перегрузка операторов. 
Класс дополнен возможностью совершать следующие операции над объектами:
•	Инкремент, декремент на объектами класса Strin.
•	Сложение объектов класса Strin.
•	сравнения объектов класса Strin.
•	присваивания объекта класса Strin.
•	приведения объекта класса String к типу int.
•	>> << объекта класса Strin.


V 3.*.* -Динамический полиморфизм.
Разработка абстрактного класса, который определяет минимально необходимый интерфейс.
Производный класс , осуществив его наследование от разработанного абстрактного класса, с реализацией всех чисто виртуальных функций. Добавляно в класс: 
Static ДИНАМИЧЕСКИЙ массив указателей на объекты БАЗОВОГО (абстрактного) класса.
Статические переменные для хранения размера массива. Статические функции: 
-добавления указателя (типа Abstract**) на объект данного класса. 
-удаление элемента с заданным номером -обход всего массива с вызовом функции Print. 
Пользовательский интерфейс: 
-создание нового объекта (и автоматическое добавление его в массив) 
-ввод новых значений для объекта с заданным номером -удаление по логическому номеру 
-просмотр всего массива ПРИМЕЧАНИЕ: для этих операций используются разработанные static методы.
