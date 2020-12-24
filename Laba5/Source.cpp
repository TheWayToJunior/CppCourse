#include <iostream>
#include "Task1/DataManager.cpp"
#include "Task2/Reader.h"
#include "Task3-4/Book.h"
#include "Task5/Cache.h"

int main()
{
   // Написать шаблонный класс DataManager<T> для специфической работы с набором
   // однотипных данных(максимальная вместимость равна 64 элементам).В набор можно
   // добавлять данные(метод push(T elem) для добавления одного элемента и метод
   // push(T elems[], size_t n) для добавления группы из n элементов), считывать без
   // извлечения(метод T peek()) и извлекать(метод T pop()) по некоторым алгоритмам
   // (в соответствии с вариантом, приложение А).Если набор заполнен на 100 % и
   // поступает команда добавления нового элемента(ов), то данные полностью
   // выгружаются(дописываются) в специальный файл dump.dat, а сам массив очищается
   // и новые данные записываются уже в обновленный набор.

    DataManager<int> i;
    int mass[3] = { 1, 2, 3 };
    i.push(mass, 3);
    auto value1 = i.peek();

    DataManager<char> c;
    char mass2[3] = { 1, 2, 3 };
    c.push('T');
    auto value2 = c.popLower();


    // Написать код для чтения произвольного текстового файла и вывода на экран всех слов
    // размером более 3 букв, встречающихся в нем не менее 7 раз, в порядке убывания
    // частоты встречаемости(приложение А).В качестве разделителей слов рассматривать
    // пробел, точку, запятую, тире, двоеточие, восклицательный знак, точку с запятой.
    // Использовать контейнер std::map.

    Reader r;
    auto map = r.reade();

    for (auto mass_it = map.begin(); mass_it != map.end(); ++mass_it)
    {
        std::cout << mass_it->first << ":(" << mass_it->second << ")" << std::endl;
    }

    // Создать класс книги Book, в котором хранится название, автор и год издания книги. В
    // главной функции создать коллекцию книг (приложение А). Продемонстрировать
    // сортировку книг по автору (первичный ключ) и названию (вторичный ключ).
    // Продемонстрировать поиск в коллекции: найти все книги, год издания которых
    // находится в указанном диапазоне. Использовать контейнер std::vector и функторы.

    std::vector<Book> books{ Book("A", "A", 2001), Book("B", "B", 2002), Book("C", "C", 2003) };
    std::sort(books.begin(), books.end(), [](Book f, Book l) { return f.year > l.year; });

    for (auto book : books)
    {
        std::cout << book.author << std::endl;
    }

    std::vector<Book>::iterator finder = std::find_if(books.begin(), books.end(), [](Book book)
    {
        if (2001 < book.year && book.year < 2003)
        {
            return true;
        }

        return false;
    });

    int mycount = std::count_if(books.begin(), books.end(), [](Book book) { return book.year > 2009; });


    // Написать шаблонный класс кэша данных Cache<T> с методом добавления элемента в
    // кеш put(T elem) и его аналогом – оператором +=, а также методом проверки наличия
    // элемента в кеше bool contains(T elem). Написать явную специализацию шаблона
    // для типа std::string с такими нюансами: метод contains() должен возвращать true
    // по совпадению первого символа строки; метод add() должен генерировать
    // исключение, если в кеше уже есть 100 строк. В главной функции инстанцировать
    // Cache с типами int и std::string

    Cache<int> cache;
    cache.put(1);
    cache.put(2);
    cache.put(3);
    cache += 5;

    Cache<std::string> voc;
    voc.put("ooooo");

    std::cout << voc.contains("o") << std::endl;
    std::cout << cache.contains(5) << std::endl;
}
