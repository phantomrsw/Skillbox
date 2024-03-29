**Задание 1. Реализация ведомости учёта**

**Что нужно сделать:**
Вы уже создавали программу чтения и записи ведомости. Теперь её надо будет обобщить и дополнить
использованием структур.
Формат ведомости прежний: сначала идёт имя и фамилия получателя денежных средств, далее — дата выдачи
в формате ДД.ММ.ГГГГ, затем — сумма выплаты в рублях. Данные разделяются пробелами. В конце каждой
записи должен быть перевод строки.
Структура данных записи должна соответствовать указанному формату.
При старте программы пользователь указывает команду, которую следует осуществить: *list* или *add*.
Команда *list* осуществляет чтение из файла ведомости, как и прежде, только уже в структуры данных,
и отображает их на экране.
Команда *add* добавляет новую запись в конец ведомости.

**Советы и рекомендации:**
Чтобы определить конец файла, используйте, как и прежде, функцию `file.eof()`. Из-за завершающего
переноса строки также стоит проверить и имя. Если оно пустое, то файл закончился.
Используйте вектор структур. Для выбора команды потребуется подобная конструкция:
```
if (command == "list") 
{ 
… 
}
```
**Что оценивается:**
Корректность работы программы. Программа должна всегда использовать структуры и все операции проводить
через них.

**Как отправить работу на проверку:**
Пришлите ссылку на repl.it или файл CPP с решением через форму ниже.