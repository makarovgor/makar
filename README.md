# Finanse-Information-Systems

Тестовое задание для стажеров аналитиков-технологов

Необходимо разработать некоторые части приложения для учета книг в библиотеке. Описание данных, с которыми будет работать приложение – ниже.
Приложение для учета книг в библиотеке должно:
1. Хранить названия книг, ФИО авторов, наименования издательств, год издания.
2. Учитывать имеющиеся в библиотеке экземпляры конкретной книги.
3. Учитывать студентов, которым выдавалась конкретная книга. При каждой выдаче книги студенту, фиксируется дата выдачи. При возврате – дата возврата книги.
Задания:
1. Опишите модель данных (в любом удобном для вас представлении) для обслуживания библиотеки. Это может быть описание таблиц с типами данных, диаграмма – что угодно.
2. Напишите SQL-запрос, который бы возвращал самого популярного автора за год. Запрос должен основываться на модели данных, которую вы описали в задании 1. 
3. Определите понятие «злостный читатель».  Предложите алгоритм для поиска самого злостного читателя библиотеки. На  любом языке программирования опишите алгоритм поиска такого читателя. Алгоритм должен основываться на модели данных, которую вы описали в задании 1.


## Порядок выполнения

1. Составил таблицу Реляционной базы данных для Библиотеки. Файл "Library.pdf".
2. Сделал SQL-запрос для получения самого поппулярного автора за год. Файл "SQL-запрос.rtf".
3. Создал базу данных на основе данных из первого файла, используя классы и наследования, описал методы и поля.
  Определимся кто такой "Злостный читаль" - читатель, у котого сумарный срок задолжности больше всех (установленный библиотекой срок сдачи книги 30 дней).
  Алгоритм по нахождению такого читателя описан на "98 - 108" и "172 - 190" строках файла "main.cpp".
-Сначала мы составляем базу данных. 
-Затем в три массива "unsigned long students[100], string issues[100], string returnes[100" запишем по-порядку, кто брал книгу, когда и когда вернул.
-Далее, находим период на который брали книгу, описано в методе "period_of_issues" : приводим дату к формату ГГГГММДД ->
-затем по формуле (Г*1000 + Г*100 + Г * 10 + Г) + (М*10 + М) * 30 + (Д*10 + Д) находим какой день это был -> 
-вычитаем разницу дней, если она больше 30 (установленного срока), то в массив "zlostnost[500]", где индекс ячейки = id студента прибавляем эту разницу.
-Далее, находим max этого массива и выводим индекс = id студента. Злостный читатель найден.
