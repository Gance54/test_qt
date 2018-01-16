#-------------------------------------------------
#
# Project created by QtCreator 2017-09-02T21:09:36
#
#-------------------------------------------------

QT       += core
QT       += gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testqt
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    calendar.cpp \
    database.cpp \
    exception.cpp \
    listview.cpp \
    fileoperations.cpp \
    main_db/maindatabase.cpp \
    labelmapper.cpp \
    descriptiondialog.cpp

HEADERS  += mainwindow.h \
    ui_mainwindow.h \
    ui_calendar.h \
    calendar.h \
    database.h \
    exception.h \
    ui_listview.h \
    listview.h \
    fileoperations.h \
    main_db/maindatabase.h \
    labelmapper.h \
    ui_description.h \
    descriptiondialog.h

FORMS    += mainwindow.ui \
    calendar.ui \
    listview.ui \
    description.ui

DISTFILES += \
    testqt \
    data/get_info.sh \
    data_reserved/get_info.sh \
    database.dat \
    data/categories/Бахчевые.txt \
    data/categories/Бобовые.txt \
    data/categories/Грибы.txt \
    data/categories/Зерновые.txt \
    data/categories/Изделия из муки.txt \
    data/categories/Кондитерские изделия.txt \
    data/categories/Крупы.txt \
    data/categories/Масла и жиры.txt \
    data/categories/Молочные продукты.txt \
    data/categories/Мясные продукты.txt \
    data/categories/Напитки.txt \
    data/categories/Овощи сушенные.txt \
    data/categories/Овощи.txt \
    data/categories/Орехи и семечки.txt \
    data/categories/Плодоовощные консервы.txt \
    data/categories/Птица.txt \
    data/categories/Рыба и морепродукты.txt \
    data/categories/Сырье.txt \
    data/categories/Фрукты сушенные.txt \
    data/categories/Фрукты.txt \
    data/categories/Цитрусовые.txt \
    data/categories/Ягоды.txt \
    data/consumables/белки.txt \
    data/consumables/витамин А(ретинол).txt \
    data/consumables/витамин В1 (тиамин).txt \
    data/consumables/витамин В2 (рибофлавин).txt \
    data/consumables/витамин В9 (фолиевая кислота).txt \
    data/consumables/витамин Е(токоферол).txt \
    data/consumables/витамин РР (ниацин).txt \
    data/consumables/витамин С (аскорбиновая кислота).txt \
    data/consumables/вода.txt \
    data/consumables/железо.txt \
    data/consumables/жиры.txt \
    data/consumables/йод.txt \
    data/consumables/калий.txt \
    data/consumables/калорийность.txt \
    data/consumables/кальций.txt \
    data/consumables/кобальт.txt \
    data/consumables/магний.txt \
    data/consumables/марганец.txt \
    data/consumables/медь.txt \
    data/consumables/молибден.txt \
    data/consumables/натрий.txt \
    data/consumables/углеводы.txt \
    data/consumables/фосфор.txt \
    data/consumables/фтор.txt \
    data/consumables/цинк.txt \
    data/products/ Ацидофилин.txt \
    data/products/560Консервы натуральные "креветки".txt \
    data/products/Абрикосовый сок.txt \
    data/products/Абрикосы.txt \
    data/products/Агар из фурцеллярии.txt \
    data/products/Агар пищевой.txt \
    data/products/Айва.txt \
    data/products/Айвовый сок.txt \
    data/products/Алыча.txt \
    data/products/Ананас.txt \
    data/products/Апельсин.txt \
    data/products/Апельсиновый сок.txt \
    data/products/Арахис сушеный.txt \
    data/products/Арахис.txt \
    data/products/Арбуз.txt \
    data/products/Баклажаны в томатном соусе.txt \
    data/products/Баклажаны.txt \
    data/products/Балык осетровый вяленый.txt \
    data/products/Балык осетровый холодного копчения.txt \
    data/products/Бананы.txt \
    data/products/Баранина 1 категории.txt \
    data/products/Баранки простые.txt \
    data/products/Баранки сдобные.txt \
    data/products/Баранья грудинка.txt \
    data/products/Баранья корейка .txt \
    data/products/Баранья тазобедренная часть.txt \
    data/products/Батон нарезной 1 сорт.txt \
    data/products/Батончики на кондитерском жире.txt \
    data/products/Белые свежие.txt \
    data/products/Белые сушеные.txt \
    data/products/Бобы зелёные.txt \
    data/products/Брусника.txt \
    data/products/Брынза из коровьего молока.txt \
    data/products/Брынза из овечьего молока.txt \
    data/products/Брюква.txt \
    data/products/Бублики простые.txt \
    data/products/Бублики с маком.txt \
    data/products/Буйволятина 1 категории.txt \
    data/products/Булка городская.txt \
    data/products/Булочка сдобная.txt \
    data/products/Варенье из клубники.txt \
    data/products/Варенье из малины.txt \
    data/products/Варенье из сливы.txt \
    data/products/Варенье из яблок.txt \
    data/products/Вафли с жирной начинкой.txt \
    data/products/Вафли с фруктовой начинкой.txt \
    data/products/Верблюжатина 1 категории.txt \
    data/products/Ветчина из свинины в форме.txt \
    data/products/Ветчина особая.txt \
    data/products/Вино десертное белое 16% об..txt \
    data/products/Вино столовое белое 11% об..txt \
    data/products/Вино столовое красное 12% об..txt \
    data/products/Виноград.txt \
    data/products/Виноградный сок.txt \
    data/products/Вишневий сок.txt \
    data/products/Вишня.txt \
    data/products/Вобла каспийская вяленая.txt \
    data/products/Вобла свежая.txt \
    data/products/Вобла холодного копчения.txt \
    data/products/Водка 40%об..txt \
    data/products/Вымя говяжье.txt \
    data/products/Галеты из муки в-с.txt \
    data/products/Геркулес.txt \
    data/products/Говядина 1 категории.txt \
    data/products/Говядина в собственном соку.txt \
    data/products/Говядина тушеная.txt \
    data/products/Говяжья вырезка.txt \
    data/products/Говяжья грудинка.txt \
    data/products/Говяжья тазобедренная часть.txt \
    data/products/Голубика.txt \
    data/products/Горбуша солёная.txt \
    data/products/Горбуша.txt \
    data/products/Горох лущенный.txt \
    data/products/Горох сухой.txt \
    data/products/Горошек зелёный.txt \
    data/products/Гранат.txt \
    data/products/Гранатовый сок.txt \
    data/products/Грейпфрут.txt \
    data/products/Грейпфрутовый сок.txt \
    data/products/Грецкие орехи.txt \
    data/products/Гречиха.txt \
    data/products/Гречневая (продел).txt \
    data/products/Гречневая.txt \
    data/products/Грудинка свиная копчено-запеченная.txt \
    data/products/Грудинка свиная сырокопченая.txt \
    data/products/Груша.txt \
    data/products/Гуси 1 категории.txt \
    data/products/Джем из абрикосов.txt \
    data/products/Джем из чёрной смородины.txt \
    data/products/Драже ореховое.txt \
    data/products/Драже фруктовое в шоколаде.txt \
    data/products/Дрожжи прессованные.txt \
    data/products/Дыня.txt \
    data/products/Ежевика.txt \
    data/products/Желатин пищевой.txt \
    data/products/Желудок куриный.txt \
    data/products/Жир бараний топленый.txt \
    data/products/Жир говяжий топленый.txt \
    data/products/Жир кондитерский.txt \
    data/products/Жир кулинарный "Прима".txt \
    data/products/Жир свиной топленый.txt \
    data/products/Жир тресковый.txt \
    data/products/Завтрак туриста (говядина).txt \
    data/products/Зелёный горошек.txt \
    data/products/Земляника.txt \
    data/products/Зефир.txt \
    data/products/Изюм.txt \
    data/products/Икра горбуши зернистая.txt \
    data/products/Икра из баклажан.txt \
    data/products/Икра из кабачков.txt \
    data/products/Икра кеты зернистая (красная).txt \
    data/products/Икра минтаевая пробойная.txt \
    data/products/Икра осетровая зернистая.txt \
    data/products/Икра осетровая паюсная.txt \
    data/products/Индейки 1 категории.txt \
    data/products/Инжир.txt \
    data/products/Ирис полутвердый.txt \
    data/products/Йогурт сладкий.txt \
    data/products/Йогурт.txt \
    data/products/Кабачки.txt \
    data/products/Какао со сгущ. молоком.txt \
    data/products/Какао тёртое.txt \
    data/products/Какао-порошок.txt \
    data/products/Калач московский.txt \
    data/products/Кальмар (мясо).txt \
    data/products/Капуста белокочанная.txt \
    data/products/Капуста брюссельская.txt \
    data/products/Капуста квашеная.txt \
    data/products/Капуста кольраби.txt \
    data/products/Капуста краснокочанная.txt \
    data/products/Капуста цветная.txt \
    data/products/Карамель леденцовая.txt \
    data/products/Карамель с ликёром.txt \
    data/products/Карамель фруктовая .txt \
    data/products/Карамель шоколадно-ореховая.txt \
    data/products/Карп.txt \
    data/products/Картофель молодой.txt \
    data/products/Картофель сладкий (батат).txt \
    data/products/Картофель.txt \
    data/products/Картофельное пюре (хлопья).txt \
    data/products/Квас хлебный 0.8% об..txt \
    data/products/Кефир жирный.txt \
    data/products/Кефир нежирный.txt \
    data/products/Кизил.txt \
    data/products/Килька балтийская солёная.txt \
    data/products/Килька балтийская.txt \
    data/products/Килька горячего копчения.txt \
    data/products/Килька пряного посола.txt \
    data/products/Клюква.txt \
    data/products/Колбаса в-копчёная любительская.txt \
    data/products/Колбаса вареная диабетическая.txt \
    data/products/Колбаса вареная докторская.txt \
    data/products/Колбаса вареная подмосковская.txt \
    data/products/Колбаса вареная телячья.txt \
    data/products/Колбаса вареная чайная.txt \
    data/products/Колбаса п-копчёная краковская.txt \
    data/products/Колбаса п-копчёная украинская.txt \
    data/products/Колбаса сырокопченая зернистая.txt \
    data/products/Колбаса сырокопченая сервелат.txt \
    data/products/Колбасный фарш отдельный.txt \
    data/products/Компот из абрикосов.txt \
    data/products/Компот из яблок.txt \
    data/products/Консервы "Горбуша в томате".txt \
    data/products/Консервы "Морская капуста".txt \
    data/products/Консервы "Печень трески".txt \
    data/products/Консервы "Ставрида в масле".txt \
    data/products/Консервы "Ставрида в томате".txt \
    data/products/Консервы "Судак в томате".txt \
    data/products/Консервы "Треска в масле".txt \
    data/products/Консервы в масле "Шпроты".txt \
    data/products/Консервы натуральные "Горбуша".txt \
    data/products/Консервы натуральные "крабы".txt \
    data/products/Консервы натуральные "Скумбрия".txt \
    data/products/Конфеты грильяжные.txt \
    data/products/Конфеты кремовые.txt \
    data/products/Конфеты молочные.txt \
    data/products/Конфеты помадные.txt \
    data/products/Конфеты фруктовые.txt \
    data/products/Конфеты шоколадные.txt \
    data/products/Коньяк "3 звёздочки" 40%об..txt \
    data/products/Корейка свиная сырокопченая.txt \
    data/products/Кофе жареный в зернах.txt \
    data/products/Кофе растворимый.txt \
    data/products/Кофе со сгущ. молоком.txt \
    data/products/Краб камчатский (мясо).txt \
    data/products/Крахмал картофельный.txt \
    data/products/Крахмал кукурузный.txt \
    data/products/Креветка (мясо).txt \
    data/products/Крекеры из муки в-с.txt \
    data/products/Крыжовник.txt \
    data/products/Кукуруза сахарная.txt \
    data/products/Кукуруза целыми зернами.txt \
    data/products/Кукуруза.txt \
    data/products/Кукурузная.txt \
    data/products/Кумыс из кобыльего молока.txt \
    data/products/Кумыс из коровьего молока.txt \
    data/products/Курага.txt \
    data/products/Курица в собственном соку.txt \
    data/products/Куры 1 категории.txt \
    data/products/Лаваш.txt \
    data/products/Лепешка ржаная.txt \
    data/products/Лещ горячего копчения.txt \
    data/products/Лещ каспийский вяленый.txt \
    data/products/Лещ каспийский солёный.txt \
    data/products/Лещ морской.txt \
    data/products/Лещ холодного копчения.txt \
    data/products/Лещ.txt \
    data/products/Ликёр "Вишнёвый" 25%об.txt \
    data/products/Лимон.txt \
    data/products/Лимонад плодовоягодный.txt \
    data/products/Лимонад цитрусовый.txt \
    data/products/Лимонный сок.txt \
    data/products/Лисички свежие.txt \
    data/products/Лук зелёный.txt \
    data/products/Лук репчатый.txt \
    data/products/Лук-порей.txt \
    data/products/Майонез "Провансаль".txt \
    data/products/Майонез столовый молочный.txt \
    data/products/Макаронные изделия, в-с.txt \
    data/products/Макароны молочные.txt \
    data/products/Макароны яичные.txt \
    data/products/Малина.txt \
    data/products/Мандарин.txt \
    data/products/Мандариновый сок.txt \
    data/products/Манная.txt \
    data/products/Маргарин "Экстра".txt \
    data/products/Маргарин столовый молочный.txt \
    data/products/Мармелад фруктово-ягодный.txt \
    data/products/Масло бутербродное.txt \
    data/products/Масло крестьянское несолёное.txt \
    data/products/Масло крестьянское солёное.txt \
    data/products/Масло кукурузное.txt \
    data/products/Масло кунжутное.txt \
    data/products/Масло оливковое.txt \
    data/products/Масло подсолнечное.txt \
    data/products/Масло сливочное несолёное.txt \
    data/products/Масло соевое.txt \
    data/products/Масло топленое.txt \
    data/products/Маслята свежие.txt \
    data/products/Мидии.txt \
    data/products/Миндаль сладкий.txt \
    data/products/Минтай.txt \
    data/products/Мойва весенняя.txt \
    data/products/Мойва осенняя.txt \
    data/products/Моллюск рапана.txt \
    data/products/Молоко козье (сырое).txt \
    data/products/Молоко коровье (паст.).txt \
    data/products/Молоко коровье (стерил.).txt \
    data/products/Молоко коровье (сырое).txt \
    data/products/Молоко обезжиренное.txt \
    data/products/Молоко сгущеное (с сахаром).txt \
    data/products/Молоко сгущеное (стерил.).txt \
    data/products/Молоко сухое цельное.txt \
    data/products/Молоко топленое.txt \
    data/products/Молочное клубничное.txt \
    data/products/Молочное крем-брюле.txt \
    data/products/Молочное ореховое.txt \
    data/products/Молочное шоколадное.txt \
    data/products/Морковный сок.txt \
    data/products/Морковь.txt \
    data/products/Мороженое молочное.txt \
    data/products/Мороженое сливочное.txt \
    data/products/Морошка.txt \
    data/products/Морская капуста.txt \
    data/products/Мука кукурузная.txt \
    data/products/Мука пшеничная обойная.txt \
    data/products/Мука пшеничная, 1 сорт.txt \
    data/products/Мука пшеничная, 2 сорт.txt \
    data/products/Мука пшеничная, в-с.txt \
    data/products/Мука ржаная обдирная.txt \
    data/products/Мука ржаная обойная.txt \
    data/products/Мука ржаная сеяная.txt \
    data/products/Мука соевая обезжиренная.txt \
    data/products/Мука соевая.txt \
    data/products/Мука ячменная.txt \
    data/products/Мясной хлеб ветчинный.txt \
    data/products/Мясо кролика.txt \
    data/products/Мясо ластоногих.txt \
    data/products/Мясо поросят.txt \
    data/products/Мясо яка.txt \
    data/products/Мёд натуральный.txt \
    data/products/Наливка "Сливянка" 18%об..txt \
    data/products/Настойка "Старка" 43%об..txt \
    data/products/Облепиха.txt \
    data/products/Овес.txt \
    data/products/Овсяная.txt \
    data/products/Огурцы солёные.txt \
    data/products/Огурцы.txt \
    data/products/Окорок свиной вареный.txt \
    data/products/Окорочек куриный.txt \
    data/products/Окунь морской гор. копчения.txt \
    data/products/Окунь морской свежий.txt \
    data/products/Окунь речной.txt \
    data/products/Окунь холодного копчения(балычок).txt \
    data/products/Оленина 1 категории.txt \
    data/products/Оливки консервированные.txt \
    data/products/Опята свежие.txt \
    data/products/Осетр.txt \
    data/products/Отруби пшеничные.txt \
    data/products/Охотничьи колбаски п-копчёные.txt \
    data/products/Паста ацидофильная нежирная.txt \
    data/products/Паста ацидофильная сладкая.txt \
    data/products/Паста яблочная с сахаром.txt \
    data/products/Паста"Океан".txt \
    data/products/Пастернак (корень).txt \
    data/products/Пастила.txt \
    data/products/Патиссоны.txt \
    data/products/Патока кукурузная.txt \
    data/products/Пахта пастеризованная.txt \
    data/products/Пахта сквашенная.txt \
    data/products/Паштет мясной.txt \
    data/products/Паштет печёночный.txt \
    data/products/Пектин.txt \
    data/products/Пельмени мясные.txt \
    data/products/Перепёлки 1 категории.txt \
    data/products/Перец зелёный сладкий.txt \
    data/products/Перец красный сладкий.txt \
    data/products/Перловая.txt \
    data/products/Персики.txt \
    data/products/Персиковый сок.txt \
    data/products/Петрушка (корень).txt \
    data/products/Петрушка.txt \
    data/products/Печень говяжья.txt \
    data/products/Печень куриная .txt \
    data/products/Печень свиная.txt \
    data/products/Печенье миндальное.txt \
    data/products/Печенье сахарное в-с.txt \
    data/products/Печенье сдобное.txt \
    data/products/Пиво "Портер" 5%об..txt \
    data/products/Пиво жигулевское 2.8% об. .txt \
    data/products/Пикша.txt \
    data/products/Пирожное крошковое.txt \
    data/products/Пирожное миндальное.txt \
    data/products/Пирожное слоёное с кремом.txt \
    data/products/Пирожное трубочка с кремом .txt \
    data/products/Пирожное фруктовое.txt \
    data/products/Пломбир крем-брюле.txt \
    data/products/Пломбир ореховый.txt \
    data/products/Пломбир шоколадный.txt \
    data/products/Пломбир.txt \
    data/products/Плюшка московская.txt \
    data/products/Повидло яблочное.txt \
    data/products/Подосиновики свежие.txt \
    data/products/Подосиновики сушеные.txt \
    data/products/Подсолнечник (семена).txt \
    data/products/Порошок горчичный.txt \
    data/products/Почки говяжьи.txt \
    data/products/Просо.txt \
    data/products/Простокваша Мечниковская.txt \
    data/products/Простокваша.txt \
    data/products/Пряники заварные.txt \
    data/products/Пунш "Чёрносмородиновый"17%об.txt \
    data/products/Пшеница мягкая озимая.txt \
    data/products/Пшеница твёрдая.txt \
    data/products/Пшеничная "Полтавская".txt \
    data/products/Пшенная.txt \
    data/products/Пюре яблочное.txt \
    data/products/Ревень (черешки).txt \
    data/products/Редис.txt \
    data/products/Редька.txt \
    data/products/Репа.txt \
    data/products/Рис.txt \
    data/products/Рисовая.txt \
    data/products/Рожки обсыпные.txt \
    data/products/Рожь.txt \
    data/products/Рыжики свежие.txt \
    data/products/Рябина.txt \
    data/products/Ряженка 6% жирности.txt \
    data/products/Сайра крупная.txt \
    data/products/Сайра мелкая.txt \
    data/products/Салат.txt \
    data/products/Сардельки говяжьи.txt \
    data/products/Сардельки свиные.txt \
    data/products/Сахар-песок.txt \
    data/products/Сахар-рафинад.txt \
    data/products/Сахар-сырец.txt \
    data/products/Свекла.txt \
    data/products/Свекольный сок.txt \
    data/products/Свиная тазобедренная часть.txt \
    data/products/Свинина вырезка.txt \
    data/products/Свинина грудинка.txt \
    data/products/Свинина жирная.txt \
    data/products/Свинина корейка.txt \
    data/products/Свинина мясная.txt \
    data/products/Свинина тушеная.txt \
    data/products/Свиные ножки.txt \
    data/products/Сдоба выборгская с маком.txt \
    data/products/Сельдерей (корень).txt \
    data/products/Сельдерей.txt \
    data/products/Сельдь атлантическая солёная.txt \
    data/products/Сельдь жирная свежая.txt \
    data/products/Сельдь нежирная свежая.txt \
    data/products/Сердце говяжье.txt \
    data/products/Сердце куриное.txt \
    data/products/Скумбрия атлантическая.txt \
    data/products/Слива.txt \
    data/products/Сливки 10% жирности.txt \
    data/products/Сливки 20% жирности.txt \
    data/products/Сливки 35% жирности.txt \
    data/products/Сливки взбитые плодовые.txt \
    data/products/Сливки взбитые с шоколадом.txt \
    data/products/Сливки сгущ. с сахаром.txt \
    data/products/Сливки сухие высокожирные.txt \
    data/products/Сливки сухие.txt \
    data/products/Сливовый сок.txt \
    data/products/Сливочное клубничное.txt \
    data/products/Сливочное крем-брюле.txt \
    data/products/Сливочное ореховое.txt \
    data/products/Сливочное шоколадное.txt \
    data/products/Сметана 10% жирности.txt \
    data/products/Сметана 20% жирности.txt \
    data/products/Сметана 30% жирности.txt \
    data/products/Сметана 40% жирности.txt \
    data/products/Смородина белая.txt \
    data/products/Смородина красная.txt \
    data/products/Смородина чёрная.txt \
    data/products/Снеток солено-сушеный.txt \
    data/products/Соломка сладкая.txt \
    data/products/Соль поваренная.txt \
    data/products/Сосиски любительские.txt \
    data/products/Сосиски молочные.txt \
    data/products/Соус томатный острый.txt \
    data/products/Соя.txt \
    data/products/Спаржа.txt \
    data/products/Ставрида океаническая.txt \
    data/products/Ставрида хол. копчения.txt \
    data/products/Судак.txt \
    data/products/Сухари армейские.txt \
    data/products/Сухари дорожные.txt \
    data/products/Сухари сливочные в-с.txt \
    data/products/Сушки ванильные.txt \
    data/products/Сушки горчичные.txt \
    data/products/Сушки простые.txt \
    data/products/Сыворотка подсырная.txt \
    data/products/Сыворотка творожная.txt \
    data/products/Сыр "Вырусский".txt \
    data/products/Сыр "Голландский".txt \
    data/products/Сыр "Пошехонский".txt \
    data/products/Сыр "Прибалтийский".txt \
    data/products/Сыр "Рокфор".txt \
    data/products/Сыр "Российский".txt \
    data/products/Сыр колбасный копчёный.txt \
    data/products/Сыр плавленый "Российский".txt \
    data/products/Сырки глазированные.txt \
    data/products/Сырки масса творожная.txt \
    data/products/Сырки творожные детские.txt \
    data/products/Творог жирный.txt \
    data/products/Творог мягкий диетический.txt \
    data/products/Творог нежирный.txt \
    data/products/Творог полужирный.txt \
    data/products/Творожная масса сладкая.txt \
    data/products/Телятина 1 категории.txt \
    data/products/Толокно.txt \
    data/products/Томат-пюре.txt \
    data/products/Томатная паста.txt \
    data/products/Томатный сок.txt \
    data/products/Томаты с кожицей.txt \
    data/products/Томаты.txt \
    data/products/Торт с фруктовой начинкой.txt \
    data/products/Торт слоёный с кремом.txt \
    data/products/Треска горячего копчения.txt \
    data/products/Треска солёная.txt \
    data/products/Треска.txt \
    data/products/Тунец.txt \
    data/products/Тыква.txt \
    data/products/Угорь.txt \
    data/products/Укроп.txt \
    data/products/Уксус 3%-ный.txt \
    data/products/Урюк.txt \
    data/products/Утки 1 категории.txt \
    data/products/Фарш колбасный куриный.txt \
    data/products/Фарш свиной сосисочный.txt \
    data/products/Фасоль (стручок).txt \
    data/products/Фасоль стручковая.txt \
    data/products/Фасоль.txt \
    data/products/Филе куриное.txt \
    data/products/Финики.txt \
    data/products/Фундук.txt \
    data/products/Халва подсолнечная.txt \
    data/products/Халва тахинная.txt \
    data/products/Хлеб бородинский.txt \
    data/products/Хлеб паляница.txt \
    data/products/Хлеб пеклеванный.txt \
    data/products/Хлеб пшеничный зерновой.txt \
    data/products/Хлеб пшеничный, 1 сорт.txt \
    data/products/Хлеб ржано-пшеничный.txt \
    data/products/Хлеб ржаной формовой.txt \
    data/products/Хрен.txt \
    data/products/Хурма.txt \
    data/products/Чай черный байховый.txt \
    data/products/Чебурек.txt \
    data/products/Черемша.txt \
    data/products/Черешня.txt \
    data/products/Черника.txt \
    data/products/Черноплодная рябина.txt \
    data/products/Чернослив.txt \
    data/products/Черносмородиновый сок.txt \
    data/products/Чеснок.txt \
    data/products/Чечевица.txt \
    data/products/Шампанское полусухое 12%об..txt \
    data/products/Шампиньоны свежие.txt \
    data/products/Шелковица.txt \
    data/products/Шиповник свежий.txt \
    data/products/Шиповник сухой.txt \
    data/products/Шиповниковый сок.txt \
    data/products/Шоколад без добавлений.txt \
    data/products/Шоколад молочный.txt \
    data/products/Шоколад с орехами.txt \
    data/products/Шпик свиной (без шкурки).txt \
    data/products/Шпик свиной солёный.txt \
    data/products/Шпинат-пюре.txt \
    data/products/Шпинат.txt \
    data/products/Щавель.txt \
    data/products/Щука .txt \
    data/products/Эскимо.txt \
    data/products/Яблоки в сиропе.txt \
    data/products/Яблоки зимние.txt \
    data/products/Яблоки.txt \
    data/products/Яблочный сок.txt \
    data/products/Язык говяжий.txt \
    data/products/Язык свиной.txt \
    data/products/Яичный порошок.txt \
    data/products/Яйцо куриное (белок).txt \
    data/products/Яйцо куриное (желток).txt \
    data/products/Яйцо куриное.txt \
    data/products/Яйцо перепелиное .txt \
    data/products/Ячменевая.txt \
    data/products/Ячмень.txt \
    data/categories.txt \
    data_reserved/categories/Бахчевые.txt \
    data_reserved/categories/Бобовые.txt \
    data_reserved/categories/Грибы.txt \
    data_reserved/categories/Зерновые.txt \
    data_reserved/categories/Изделия из муки.txt \
    data_reserved/categories/Кондитерские изделия.txt \
    data_reserved/categories/Крупы.txt \
    data_reserved/categories/Масла и жиры.txt \
    data_reserved/categories/Молочные продукты.txt \
    data_reserved/categories/Мясные продукты.txt \
    data_reserved/categories/Напитки.txt \
    data_reserved/categories/Овощи сушенные.txt \
    data_reserved/categories/Овощи.txt \
    data_reserved/categories/Орехи и семечки.txt \
    data_reserved/categories/Плодоовощные консервы.txt \
    data_reserved/categories/Птица.txt \
    data_reserved/categories/Рыба и морепродукты.txt \
    data_reserved/categories/Сырье.txt \
    data_reserved/categories/Фрукты сушенные.txt \
    data_reserved/categories/Фрукты.txt \
    data_reserved/categories/Цитрусовые.txt \
    data_reserved/categories/Ягоды.txt \
    data_reserved/consumables/белки.txt \
    data_reserved/consumables/витамин А(ретинол).txt \
    data_reserved/consumables/витамин В1 (тиамин).txt \
    data_reserved/consumables/витамин В2 (рибофлавин).txt \
    data_reserved/consumables/витамин В9 (фолиевая кислота).txt \
    data_reserved/consumables/витамин Е(токоферол).txt \
    data_reserved/consumables/витамин РР (ниацин).txt \
    data_reserved/consumables/витамин С (аскорбиновая кислота).txt \
    data_reserved/consumables/вода.txt \
    data_reserved/consumables/железо.txt \
    data_reserved/consumables/жиры.txt \
    data_reserved/consumables/йод.txt \
    data_reserved/consumables/калий.txt \
    data_reserved/consumables/калорийность.txt \
    data_reserved/consumables/кальций.txt \
    data_reserved/consumables/кобальт.txt \
    data_reserved/consumables/магний.txt \
    data_reserved/consumables/марганец.txt \
    data_reserved/consumables/медь.txt \
    data_reserved/consumables/молибден.txt \
    data_reserved/consumables/натрий.txt \
    data_reserved/consumables/углеводы.txt \
    data_reserved/consumables/фосфор.txt \
    data_reserved/consumables/фтор.txt \
    data_reserved/consumables/цинк.txt \
    data_reserved/products/ Ацидофилин.tmp \
    data_reserved/products/ Ацидофилин.txt \
    data_reserved/products/560Консервы натуральные "креветки".tmp \
    data_reserved/products/560Консервы натуральные "креветки".txt \
    data_reserved/products/Абрикосовый сок.tmp \
    data_reserved/products/Абрикосовый сок.txt \
    data_reserved/products/Абрикосы.tmp \
    data_reserved/products/Абрикосы.txt \
    data_reserved/products/Агар из фурцеллярии.tmp \
    data_reserved/products/Агар из фурцеллярии.txt \
    data_reserved/products/Агар пищевой.tmp \
    data_reserved/products/Агар пищевой.txt \
    data_reserved/products/Айва.tmp \
    data_reserved/products/Айва.txt \
    data_reserved/products/Айвовый сок.tmp \
    data_reserved/products/Айвовый сок.txt \
    data_reserved/products/Алыча.tmp \
    data_reserved/products/Алыча.txt \
    data_reserved/products/Ананас.tmp \
    data_reserved/products/Ананас.txt \
    data_reserved/products/Апельсин.tmp \
    data_reserved/products/Апельсин.txt \
    data_reserved/products/Апельсиновый сок.tmp \
    data_reserved/products/Апельсиновый сок.txt \
    data_reserved/products/Арахис сушеный.tmp \
    data_reserved/products/Арахис сушеный.txt \
    data_reserved/products/Арахис.tmp \
    data_reserved/products/Арахис.txt \
    data_reserved/products/Арбуз.tmp \
    data_reserved/products/Арбуз.txt \
    data_reserved/products/Баклажаны в томатном соусе.tmp \
    data_reserved/products/Баклажаны в томатном соусе.txt \
    data_reserved/products/Баклажаны.tmp \
    data_reserved/products/Баклажаны.txt \
    data_reserved/products/Балык осетровый вяленый.tmp \
    data_reserved/products/Балык осетровый вяленый.txt \
    data_reserved/products/Балык осетровый холодного копчения.tmp \
    data_reserved/products/Балык осетровый холодного копчения.txt \
    data_reserved/products/Бананы.tmp \
    data_reserved/products/Бананы.txt \
    data_reserved/products/Баранина 1 категории.tmp \
    data_reserved/products/Баранина 1 категории.txt \
    data_reserved/products/Баранки простые.tmp \
    data_reserved/products/Баранки простые.txt \
    data_reserved/products/Баранки сдобные.tmp \
    data_reserved/products/Баранки сдобные.txt \
    data_reserved/products/Баранья грудинка.tmp \
    data_reserved/products/Баранья грудинка.txt \
    data_reserved/products/Баранья корейка .tmp \
    data_reserved/products/Баранья корейка .txt \
    data_reserved/products/Баранья тазобедренная часть.tmp \
    data_reserved/products/Баранья тазобедренная часть.txt \
    data_reserved/products/Батон нарезной 1 сорт.tmp \
    data_reserved/products/Батон нарезной 1 сорт.txt \
    data_reserved/products/Батончики на кондитерском жире.tmp \
    data_reserved/products/Батончики на кондитерском жире.txt \
    data_reserved/products/Белые свежие.tmp \
    data_reserved/products/Белые свежие.txt \
    data_reserved/products/Белые сушеные.tmp \
    data_reserved/products/Белые сушеные.txt \
    data_reserved/products/Бобы зелёные.tmp \
    data_reserved/products/Бобы зелёные.txt \
    data_reserved/products/Брусника.tmp \
    data_reserved/products/Брусника.txt \
    data_reserved/products/Брынза из коровьего молока.tmp \
    data_reserved/products/Брынза из коровьего молока.txt \
    data_reserved/products/Брынза из овечьего молока.tmp \
    data_reserved/products/Брынза из овечьего молока.txt \
    data_reserved/products/Брюква.tmp \
    data_reserved/products/Брюква.txt \
    data_reserved/products/Бублики простые.tmp \
    data_reserved/products/Бублики простые.txt \
    data_reserved/products/Бублики с маком.tmp \
    data_reserved/products/Бублики с маком.txt \
    data_reserved/products/Буйволятина 1 категории.tmp \
    data_reserved/products/Буйволятина 1 категории.txt \
    data_reserved/products/Булка городская.tmp \
    data_reserved/products/Булка городская.txt \
    data_reserved/products/Булочка сдобная.tmp \
    data_reserved/products/Булочка сдобная.txt \
    data_reserved/products/Варенье из клубники.tmp \
    data_reserved/products/Варенье из клубники.txt \
    data_reserved/products/Варенье из малины.tmp \
    data_reserved/products/Варенье из малины.txt \
    data_reserved/products/Варенье из сливы.tmp \
    data_reserved/products/Варенье из сливы.txt \
    data_reserved/products/Варенье из яблок.tmp \
    data_reserved/products/Варенье из яблок.txt \
    data_reserved/products/Вафли с жирной начинкой.tmp \
    data_reserved/products/Вафли с жирной начинкой.txt \
    data_reserved/products/Вафли с фруктовой начинкой.tmp \
    data_reserved/products/Вафли с фруктовой начинкой.txt \
    data_reserved/products/Верблюжатина 1 категории.tmp \
    data_reserved/products/Верблюжатина 1 категории.txt \
    data_reserved/products/Ветчина из свинины в форме.tmp \
    data_reserved/products/Ветчина из свинины в форме.txt \
    data_reserved/products/Ветчина особая.tmp \
    data_reserved/products/Ветчина особая.txt \
    data_reserved/products/Вино десертное белое 16% об..tmp \
    data_reserved/products/Вино десертное белое 16% об..txt \
    data_reserved/products/Вино столовое белое 11% об..tmp \
    data_reserved/products/Вино столовое белое 11% об..txt \
    data_reserved/products/Вино столовое красное 12% об..tmp \
    data_reserved/products/Вино столовое красное 12% об..txt \
    data_reserved/products/Виноград.tmp \
    data_reserved/products/Виноград.txt \
    data_reserved/products/Виноградный сок.tmp \
    data_reserved/products/Виноградный сок.txt \
    data_reserved/products/Вишневий сок.tmp \
    data_reserved/products/Вишневий сок.txt \
    data_reserved/products/Вишня.tmp \
    data_reserved/products/Вишня.txt \
    data_reserved/products/Вобла каспийская вяленая.tmp \
    data_reserved/products/Вобла каспийская вяленая.txt \
    data_reserved/products/Вобла свежая.tmp \
    data_reserved/products/Вобла свежая.txt \
    data_reserved/products/Вобла холодного копчения.tmp \
    data_reserved/products/Вобла холодного копчения.txt \
    data_reserved/products/Водка 40%об..tmp \
    data_reserved/products/Водка 40%об..txt \
    data_reserved/products/Вымя говяжье.tmp \
    data_reserved/products/Вымя говяжье.txt \
    data_reserved/products/Галеты из муки в-с.tmp \
    data_reserved/products/Галеты из муки в-с.txt \
    data_reserved/products/Геркулес.tmp \
    data_reserved/products/Геркулес.txt \
    data_reserved/products/Говядина 1 категории.tmp \
    data_reserved/products/Говядина 1 категории.txt \
    data_reserved/products/Говядина в собственном соку.tmp \
    data_reserved/products/Говядина в собственном соку.txt \
    data_reserved/products/Говядина тушеная.tmp \
    data_reserved/products/Говядина тушеная.txt \
    data_reserved/products/Говяжья вырезка.tmp \
    data_reserved/products/Говяжья вырезка.txt \
    data_reserved/products/Говяжья грудинка.tmp \
    data_reserved/products/Говяжья грудинка.txt \
    data_reserved/products/Говяжья тазобедренная часть.tmp \
    data_reserved/products/Говяжья тазобедренная часть.txt \
    data_reserved/products/Голубика.tmp \
    data_reserved/products/Голубика.txt \
    data_reserved/products/Горбуша солёная.tmp \
    data_reserved/products/Горбуша солёная.txt \
    data_reserved/products/Горбуша.tmp \
    data_reserved/products/Горбуша.txt \
    data_reserved/products/Горох лущенный.tmp \
    data_reserved/products/Горох лущенный.txt \
    data_reserved/products/Горох сухой.tmp \
    data_reserved/products/Горох сухой.txt \
    data_reserved/products/Горошек зелёный.tmp \
    data_reserved/products/Горошек зелёный.txt \
    data_reserved/products/Гранат.tmp \
    data_reserved/products/Гранат.txt \
    data_reserved/products/Гранатовый сок.tmp \
    data_reserved/products/Гранатовый сок.txt \
    data_reserved/products/Грейпфрут.tmp \
    data_reserved/products/Грейпфрут.txt \
    data_reserved/products/Грейпфрутовый сок.tmp \
    data_reserved/products/Грейпфрутовый сок.txt \
    data_reserved/products/Грецкие орехи.tmp \
    data_reserved/products/Грецкие орехи.txt \
    data_reserved/products/Гречиха.tmp \
    data_reserved/products/Гречиха.txt \
    data_reserved/products/Гречневая (продел).tmp \
    data_reserved/products/Гречневая (продел).txt \
    data_reserved/products/Гречневая.tmp \
    data_reserved/products/Гречневая.txt \
    data_reserved/products/Грудинка свиная копчено-запеченная.tmp \
    data_reserved/products/Грудинка свиная копчено-запеченная.txt \
    data_reserved/products/Грудинка свиная сырокопченая.tmp \
    data_reserved/products/Грудинка свиная сырокопченая.txt \
    data_reserved/products/Груша.tmp \
    data_reserved/products/Груша.txt \
    data_reserved/products/Гуси 1 категории.tmp \
    data_reserved/products/Гуси 1 категории.txt \
    data_reserved/products/Джем из абрикосов.tmp \
    data_reserved/products/Джем из абрикосов.txt \
    data_reserved/products/Джем из чёрной смородины.tmp \
    data_reserved/products/Джем из чёрной смородины.txt \
    data_reserved/products/Драже ореховое.tmp \
    data_reserved/products/Драже ореховое.txt \
    data_reserved/products/Драже фруктовое в шоколаде.tmp \
    data_reserved/products/Драже фруктовое в шоколаде.txt \
    data_reserved/products/Дрожжи прессованные.tmp \
    data_reserved/products/Дрожжи прессованные.txt \
    data_reserved/products/Дыня.tmp \
    data_reserved/products/Дыня.txt \
    data_reserved/products/Ежевика.tmp \
    data_reserved/products/Ежевика.txt \
    data_reserved/products/Желатин пищевой.tmp \
    data_reserved/products/Желатин пищевой.txt \
    data_reserved/products/Желудок куриный.tmp \
    data_reserved/products/Желудок куриный.txt \
    data_reserved/products/Жир бараний топленый.tmp \
    data_reserved/products/Жир бараний топленый.txt \
    data_reserved/products/Жир говяжий топленый.tmp \
    data_reserved/products/Жир говяжий топленый.txt \
    data_reserved/products/Жир кондитерский.tmp \
    data_reserved/products/Жир кондитерский.txt \
    data_reserved/products/Жир кулинарный "Прима".tmp \
    data_reserved/products/Жир кулинарный "Прима".txt \
    data_reserved/products/Жир свиной топленый.tmp \
    data_reserved/products/Жир свиной топленый.txt \
    data_reserved/products/Жир тресковый.tmp \
    data_reserved/products/Жир тресковый.txt \
    data_reserved/products/Завтрак туриста (говядина).tmp \
    data_reserved/products/Завтрак туриста (говядина).txt \
    data_reserved/products/Зелёный горошек.tmp \
    data_reserved/products/Зелёный горошек.txt \
    data_reserved/products/Земляника.tmp \
    data_reserved/products/Земляника.txt \
    data_reserved/products/Зефир.tmp \
    data_reserved/products/Зефир.txt \
    data_reserved/products/Изюм.tmp \
    data_reserved/products/Изюм.txt \
    data_reserved/products/Икра горбуши зернистая.tmp \
    data_reserved/products/Икра горбуши зернистая.txt \
    data_reserved/products/Икра из баклажан.tmp \
    data_reserved/products/Икра из баклажан.txt \
    data_reserved/products/Икра из кабачков.tmp \
    data_reserved/products/Икра из кабачков.txt \
    data_reserved/products/Икра кеты зернистая (красная).tmp \
    data_reserved/products/Икра кеты зернистая (красная).txt \
    data_reserved/products/Икра минтаевая пробойная.tmp \
    data_reserved/products/Икра минтаевая пробойная.txt \
    data_reserved/products/Икра осетровая зернистая.tmp \
    data_reserved/products/Икра осетровая зернистая.txt \
    data_reserved/products/Икра осетровая паюсная.tmp \
    data_reserved/products/Икра осетровая паюсная.txt \
    data_reserved/products/Индейки 1 категории.tmp \
    data_reserved/products/Индейки 1 категории.txt \
    data_reserved/products/Инжир.tmp \
    data_reserved/products/Инжир.txt \
    data_reserved/products/Ирис полутвердый.tmp \
    data_reserved/products/Ирис полутвердый.txt \
    data_reserved/products/Йогурт сладкий.tmp \
    data_reserved/products/Йогурт сладкий.txt \
    data_reserved/products/Йогурт.tmp \
    data_reserved/products/Йогурт.txt \
    data_reserved/products/Кабачки.tmp \
    data_reserved/products/Кабачки.txt \
    data_reserved/products/Какао со сгущ. молоком.tmp \
    data_reserved/products/Какао со сгущ. молоком.txt \
    data_reserved/products/Какао тёртое.tmp \
    data_reserved/products/Какао тёртое.txt \
    data_reserved/products/Какао-порошок.tmp \
    data_reserved/products/Какао-порошок.txt \
    data_reserved/products/Калач московский.tmp \
    data_reserved/products/Калач московский.txt \
    data_reserved/products/Кальмар (мясо).tmp \
    data_reserved/products/Кальмар (мясо).txt \
    data_reserved/products/Капуста белокочанная.tmp \
    data_reserved/products/Капуста белокочанная.txt \
    data_reserved/products/Капуста брюссельская.tmp \
    data_reserved/products/Капуста брюссельская.txt \
    data_reserved/products/Капуста квашеная.tmp \
    data_reserved/products/Капуста квашеная.txt \
    data_reserved/products/Капуста кольраби.tmp \
    data_reserved/products/Капуста кольраби.txt \
    data_reserved/products/Капуста краснокочанная.tmp \
    data_reserved/products/Капуста краснокочанная.txt \
    data_reserved/products/Капуста цветная.tmp \
    data_reserved/products/Капуста цветная.txt \
    data_reserved/products/Карамель леденцовая.tmp \
    data_reserved/products/Карамель леденцовая.txt \
    data_reserved/products/Карамель с ликёром.tmp \
    data_reserved/products/Карамель с ликёром.txt \
    data_reserved/products/Карамель фруктовая .tmp \
    data_reserved/products/Карамель фруктовая .txt \
    data_reserved/products/Карамель шоколадно-ореховая.tmp \
    data_reserved/products/Карамель шоколадно-ореховая.txt \
    data_reserved/products/Карп.tmp \
    data_reserved/products/Карп.txt \
    data_reserved/products/Картофель молодой.tmp \
    data_reserved/products/Картофель молодой.txt \
    data_reserved/products/Картофель сладкий (батат).tmp \
    data_reserved/products/Картофель сладкий (батат).txt \
    data_reserved/products/Картофель.tmp \
    data_reserved/products/Картофель.txt \
    data_reserved/products/Картофельное пюре (хлопья).tmp \
    data_reserved/products/Картофельное пюре (хлопья).txt \
    data_reserved/products/Квас хлебный 0.8% об..tmp \
    data_reserved/products/Квас хлебный 0.8% об..txt \
    data_reserved/products/Кефир жирный.tmp \
    data_reserved/products/Кефир жирный.txt \
    data_reserved/products/Кефир нежирный.tmp \
    data_reserved/products/Кефир нежирный.txt \
    data_reserved/products/Кизил.tmp \
    data_reserved/products/Кизил.txt \
    data_reserved/products/Килька балтийская солёная.tmp \
    data_reserved/products/Килька балтийская солёная.txt \
    data_reserved/products/Килька балтийская.tmp \
    data_reserved/products/Килька балтийская.txt \
    data_reserved/products/Килька горячего копчения.tmp \
    data_reserved/products/Килька горячего копчения.txt \
    data_reserved/products/Килька пряного посола.tmp \
    data_reserved/products/Килька пряного посола.txt \
    data_reserved/products/Клюква.tmp \
    data_reserved/products/Клюква.txt \
    data_reserved/products/Колбаса в-копчёная любительская.tmp \
    data_reserved/products/Колбаса в-копчёная любительская.txt \
    data_reserved/products/Колбаса вареная диабетическая.tmp \
    data_reserved/products/Колбаса вареная диабетическая.txt \
    data_reserved/products/Колбаса вареная докторская.tmp \
    data_reserved/products/Колбаса вареная докторская.txt \
    data_reserved/products/Колбаса вареная подмосковская.tmp \
    data_reserved/products/Колбаса вареная подмосковская.txt \
    data_reserved/products/Колбаса вареная телячья.tmp \
    data_reserved/products/Колбаса вареная телячья.txt \
    data_reserved/products/Колбаса вареная чайная.tmp \
    data_reserved/products/Колбаса вареная чайная.txt \
    data_reserved/products/Колбаса п-копчёная краковская.tmp \
    data_reserved/products/Колбаса п-копчёная краковская.txt \
    data_reserved/products/Колбаса п-копчёная украинская.tmp \
    data_reserved/products/Колбаса п-копчёная украинская.txt \
    data_reserved/products/Колбаса сырокопченая зернистая.tmp \
    data_reserved/products/Колбаса сырокопченая зернистая.txt \
    data_reserved/products/Колбаса сырокопченая сервелат.tmp \
    data_reserved/products/Колбаса сырокопченая сервелат.txt \
    data_reserved/products/Колбасный фарш отдельный.tmp \
    data_reserved/products/Колбасный фарш отдельный.txt \
    data_reserved/products/Компот из абрикосов.tmp \
    data_reserved/products/Компот из абрикосов.txt \
    data_reserved/products/Компот из яблок.tmp \
    data_reserved/products/Компот из яблок.txt \
    data_reserved/products/Консервы "Горбуша в томате".tmp \
    data_reserved/products/Консервы "Горбуша в томате".txt \
    data_reserved/products/Консервы "Морская капуста".tmp \
    data_reserved/products/Консервы "Морская капуста".txt \
    data_reserved/products/Консервы "Печень трески".tmp \
    data_reserved/products/Консервы "Печень трески".txt \
    data_reserved/products/Консервы "Ставрида в масле".tmp \
    data_reserved/products/Консервы "Ставрида в масле".txt \
    data_reserved/products/Консервы "Ставрида в томате".tmp \
    data_reserved/products/Консервы "Ставрида в томате".txt \
    data_reserved/products/Консервы "Судак в томате".tmp \
    data_reserved/products/Консервы "Судак в томате".txt \
    data_reserved/products/Консервы "Треска в масле".tmp \
    data_reserved/products/Консервы "Треска в масле".txt \
    data_reserved/products/Консервы в масле "Шпроты".tmp \
    data_reserved/products/Консервы в масле "Шпроты".txt \
    data_reserved/products/Консервы натуральные "Горбуша".tmp \
    data_reserved/products/Консервы натуральные "Горбуша".txt \
    data_reserved/products/Консервы натуральные "крабы".tmp \
    data_reserved/products/Консервы натуральные "крабы".txt \
    data_reserved/products/Консервы натуральные "Скумбрия".tmp \
    data_reserved/products/Консервы натуральные "Скумбрия".txt \
    data_reserved/products/Конфеты грильяжные.tmp \
    data_reserved/products/Конфеты грильяжные.txt \
    data_reserved/products/Конфеты кремовые.tmp \
    data_reserved/products/Конфеты кремовые.txt \
    data_reserved/products/Конфеты молочные.tmp \
    data_reserved/products/Конфеты молочные.txt \
    data_reserved/products/Конфеты помадные.tmp \
    data_reserved/products/Конфеты помадные.txt \
    data_reserved/products/Конфеты фруктовые.tmp \
    data_reserved/products/Конфеты фруктовые.txt \
    data_reserved/products/Конфеты шоколадные.tmp \
    data_reserved/products/Конфеты шоколадные.txt \
    data_reserved/products/Коньяк "3 звёздочки" 40%об..tmp \
    data_reserved/products/Коньяк "3 звёздочки" 40%об..txt \
    data_reserved/products/Корейка свиная сырокопченая.tmp \
    data_reserved/products/Корейка свиная сырокопченая.txt \
    data_reserved/products/Кофе жареный в зернах.tmp \
    data_reserved/products/Кофе жареный в зернах.txt \
    data_reserved/products/Кофе растворимый.tmp \
    data_reserved/products/Кофе растворимый.txt \
    data_reserved/products/Кофе со сгущ. молоком.tmp \
    data_reserved/products/Кофе со сгущ. молоком.txt \
    data_reserved/products/Краб камчатский (мясо).tmp \
    data_reserved/products/Краб камчатский (мясо).txt \
    data_reserved/products/Крахмал картофельный.tmp \
    data_reserved/products/Крахмал картофельный.txt \
    data_reserved/products/Крахмал кукурузный.tmp \
    data_reserved/products/Крахмал кукурузный.txt \
    data_reserved/products/Креветка (мясо).tmp \
    data_reserved/products/Креветка (мясо).txt \
    data_reserved/products/Крекеры из муки в-с.tmp \
    data_reserved/products/Крекеры из муки в-с.txt \
    data_reserved/products/Крыжовник.tmp \
    data_reserved/products/Крыжовник.txt \
    data_reserved/products/Кукуруза сахарная.tmp \
    data_reserved/products/Кукуруза сахарная.txt \
    data_reserved/products/Кукуруза целыми зернами.tmp \
    data_reserved/products/Кукуруза целыми зернами.txt \
    data_reserved/products/Кукуруза.tmp \
    data_reserved/products/Кукуруза.txt \
    data_reserved/products/Кукурузная.tmp \
    data_reserved/products/Кукурузная.txt \
    data_reserved/products/Кумыс из кобыльего молока.tmp \
    data_reserved/products/Кумыс из кобыльего молока.txt \
    data_reserved/products/Кумыс из коровьего молока.tmp \
    data_reserved/products/Кумыс из коровьего молока.txt \
    data_reserved/products/Курага.tmp \
    data_reserved/products/Курага.txt \
    data_reserved/products/Курица в собственном соку.tmp \
    data_reserved/products/Курица в собственном соку.txt \
    data_reserved/products/Куры 1 категории.tmp \
    data_reserved/products/Куры 1 категории.txt \
    data_reserved/products/Лаваш.tmp \
    data_reserved/products/Лаваш.txt \
    data_reserved/products/Лепешка ржаная.tmp \
    data_reserved/products/Лепешка ржаная.txt \
    data_reserved/products/Лещ горячего копчения.tmp \
    data_reserved/products/Лещ горячего копчения.txt \
    data_reserved/products/Лещ каспийский вяленый.tmp \
    data_reserved/products/Лещ каспийский вяленый.txt \
    data_reserved/products/Лещ каспийский солёный.tmp \
    data_reserved/products/Лещ каспийский солёный.txt \
    data_reserved/products/Лещ морской.tmp \
    data_reserved/products/Лещ морской.txt \
    data_reserved/products/Лещ холодного копчения.tmp \
    data_reserved/products/Лещ холодного копчения.txt \
    data_reserved/products/Лещ.tmp \
    data_reserved/products/Лещ.txt \
    data_reserved/products/Ликёр "Вишнёвый" 25%об.tmp \
    data_reserved/products/Ликёр "Вишнёвый" 25%об.txt \
    data_reserved/products/Лимон.tmp \
    data_reserved/products/Лимон.txt \
    data_reserved/products/Лимонад плодовоягодный.tmp \
    data_reserved/products/Лимонад плодовоягодный.txt \
    data_reserved/products/Лимонад цитрусовый.tmp \
    data_reserved/products/Лимонад цитрусовый.txt \
    data_reserved/products/Лимонный сок.tmp \
    data_reserved/products/Лимонный сок.txt \
    data_reserved/products/Лисички свежие.tmp \
    data_reserved/products/Лисички свежие.txt \
    data_reserved/products/Лук зелёный.tmp \
    data_reserved/products/Лук зелёный.txt \
    data_reserved/products/Лук репчатый.tmp \
    data_reserved/products/Лук репчатый.txt \
    data_reserved/products/Лук-порей.tmp \
    data_reserved/products/Лук-порей.txt \
    data_reserved/products/Майонез "Провансаль".tmp \
    data_reserved/products/Майонез "Провансаль".txt \
    data_reserved/products/Майонез столовый молочный.tmp \
    data_reserved/products/Майонез столовый молочный.txt \
    data_reserved/products/Макаронные изделия, в-с.tmp \
    data_reserved/products/Макаронные изделия, в-с.txt \
    data_reserved/products/Макароны молочные.tmp \
    data_reserved/products/Макароны молочные.txt \
    data_reserved/products/Макароны яичные.tmp \
    data_reserved/products/Макароны яичные.txt \
    data_reserved/products/Малина.tmp \
    data_reserved/products/Малина.txt \
    data_reserved/products/Мандарин.tmp \
    data_reserved/products/Мандарин.txt \
    data_reserved/products/Мандариновый сок.tmp \
    data_reserved/products/Мандариновый сок.txt \
    data_reserved/products/Манная.tmp \
    data_reserved/products/Манная.txt \
    data_reserved/products/Маргарин "Экстра".tmp \
    data_reserved/products/Маргарин "Экстра".txt \
    data_reserved/products/Маргарин столовый молочный.tmp \
    data_reserved/products/Маргарин столовый молочный.txt \
    data_reserved/products/Мармелад фруктово-ягодный.tmp \
    data_reserved/products/Мармелад фруктово-ягодный.txt \
    data_reserved/products/Масло бутербродное.tmp \
    data_reserved/products/Масло бутербродное.txt \
    data_reserved/products/Масло крестьянское несолёное.tmp \
    data_reserved/products/Масло крестьянское несолёное.txt \
    data_reserved/products/Масло крестьянское солёное.tmp \
    data_reserved/products/Масло крестьянское солёное.txt \
    data_reserved/products/Масло кукурузное.tmp \
    data_reserved/products/Масло кукурузное.txt \
    data_reserved/products/Масло кунжутное.tmp \
    data_reserved/products/Масло кунжутное.txt \
    data_reserved/products/Масло оливковое.tmp \
    data_reserved/products/Масло оливковое.txt \
    data_reserved/products/Масло подсолнечное.tmp \
    data_reserved/products/Масло подсолнечное.txt \
    data_reserved/products/Масло сливочное несолёное.tmp \
    data_reserved/products/Масло сливочное несолёное.txt \
    data_reserved/products/Масло соевое.tmp \
    data_reserved/products/Масло соевое.txt \
    data_reserved/products/Масло топленое.tmp \
    data_reserved/products/Масло топленое.txt \
    data_reserved/products/Маслята свежие.tmp \
    data_reserved/products/Маслята свежие.txt \
    data_reserved/products/Мидии.tmp \
    data_reserved/products/Мидии.txt \
    data_reserved/products/Миндаль сладкий.tmp \
    data_reserved/products/Миндаль сладкий.txt \
    data_reserved/products/Минтай.tmp \
    data_reserved/products/Минтай.txt \
    data_reserved/products/Мойва весенняя.tmp \
    data_reserved/products/Мойва весенняя.txt \
    data_reserved/products/Мойва осенняя.tmp \
    data_reserved/products/Мойва осенняя.txt \
    data_reserved/products/Моллюск рапана.tmp \
    data_reserved/products/Моллюск рапана.txt \
    data_reserved/products/Молоко козье (сырое).tmp \
    data_reserved/products/Молоко козье (сырое).txt \
    data_reserved/products/Молоко коровье (паст.).tmp \
    data_reserved/products/Молоко коровье (паст.).txt \
    data_reserved/products/Молоко коровье (стерил.).tmp \
    data_reserved/products/Молоко коровье (стерил.).txt \
    data_reserved/products/Молоко коровье (сырое).tmp \
    data_reserved/products/Молоко коровье (сырое).txt \
    data_reserved/products/Молоко обезжиренное.tmp \
    data_reserved/products/Молоко обезжиренное.txt \
    data_reserved/products/Молоко сгущеное (с сахаром).tmp \
    data_reserved/products/Молоко сгущеное (с сахаром).txt \
    data_reserved/products/Молоко сгущеное (стерил.).tmp \
    data_reserved/products/Молоко сгущеное (стерил.).txt \
    data_reserved/products/Молоко сухое цельное.tmp \
    data_reserved/products/Молоко сухое цельное.txt \
    data_reserved/products/Молоко топленое.tmp \
    data_reserved/products/Молоко топленое.txt \
    data_reserved/products/Молочное клубничное.tmp \
    data_reserved/products/Молочное клубничное.txt \
    data_reserved/products/Молочное крем-брюле.tmp \
    data_reserved/products/Молочное крем-брюле.txt \
    data_reserved/products/Молочное ореховое.tmp \
    data_reserved/products/Молочное ореховое.txt \
    data_reserved/products/Молочное шоколадное.tmp \
    data_reserved/products/Молочное шоколадное.txt \
    data_reserved/products/Морковный сок.tmp \
    data_reserved/products/Морковный сок.txt \
    data_reserved/products/Морковь.tmp \
    data_reserved/products/Морковь.txt \
    data_reserved/products/Мороженое молочное.tmp \
    data_reserved/products/Мороженое молочное.txt \
    data_reserved/products/Мороженое сливочное.tmp \
    data_reserved/products/Мороженое сливочное.txt \
    data_reserved/products/Морошка.tmp \
    data_reserved/products/Морошка.txt \
    data_reserved/products/Морская капуста.tmp \
    data_reserved/products/Морская капуста.txt \
    data_reserved/products/Мука кукурузная.tmp \
    data_reserved/products/Мука кукурузная.txt \
    data_reserved/products/Мука пшеничная обойная.tmp \
    data_reserved/products/Мука пшеничная обойная.txt \
    data_reserved/products/Мука пшеничная, 1 сорт.tmp \
    data_reserved/products/Мука пшеничная, 1 сорт.txt \
    data_reserved/products/Мука пшеничная, 2 сорт.tmp \
    data_reserved/products/Мука пшеничная, 2 сорт.txt \
    data_reserved/products/Мука пшеничная, в-с.tmp \
    data_reserved/products/Мука пшеничная, в-с.txt \
    data_reserved/products/Мука ржаная обдирная.tmp \
    data_reserved/products/Мука ржаная обдирная.txt \
    data_reserved/products/Мука ржаная обойная.tmp \
    data_reserved/products/Мука ржаная обойная.txt \
    data_reserved/products/Мука ржаная сеяная.tmp \
    data_reserved/products/Мука ржаная сеяная.txt \
    data_reserved/products/Мука соевая обезжиренная.tmp \
    data_reserved/products/Мука соевая обезжиренная.txt \
    data_reserved/products/Мука соевая.tmp \
    data_reserved/products/Мука соевая.txt \
    data_reserved/products/Мука ячменная.tmp \
    data_reserved/products/Мука ячменная.txt \
    data_reserved/products/Мясной хлеб ветчинный.tmp \
    data_reserved/products/Мясной хлеб ветчинный.txt \
    data_reserved/products/Мясо кролика.tmp \
    data_reserved/products/Мясо кролика.txt \
    data_reserved/products/Мясо ластоногих.tmp \
    data_reserved/products/Мясо ластоногих.txt \
    data_reserved/products/Мясо поросят.tmp \
    data_reserved/products/Мясо поросят.txt \
    data_reserved/products/Мясо яка.tmp \
    data_reserved/products/Мясо яка.txt \
    data_reserved/products/Мёд натуральный.tmp \
    data_reserved/products/Мёд натуральный.txt \
    data_reserved/products/Наливка "Сливянка" 18%об..tmp \
    data_reserved/products/Наливка "Сливянка" 18%об..txt \
    data_reserved/products/Настойка "Старка" 43%об..tmp \
    data_reserved/products/Настойка "Старка" 43%об..txt \
    data_reserved/products/Облепиха.tmp \
    data_reserved/products/Облепиха.txt \
    data_reserved/products/Овес.tmp \
    data_reserved/products/Овес.txt \
    data_reserved/products/Овсяная.tmp \
    data_reserved/products/Овсяная.txt \
    data_reserved/products/Огурцы солёные.tmp \
    data_reserved/products/Огурцы солёные.txt \
    data_reserved/products/Огурцы.tmp \
    data_reserved/products/Огурцы.txt \
    data_reserved/products/Окорок свиной вареный.tmp \
    data_reserved/products/Окорок свиной вареный.txt \
    data_reserved/products/Окорочек куриный.tmp \
    data_reserved/products/Окорочек куриный.txt \
    data_reserved/products/Окунь морской гор. копчения.tmp \
    data_reserved/products/Окунь морской гор. копчения.txt \
    data_reserved/products/Окунь морской свежий.tmp \
    data_reserved/products/Окунь морской свежий.txt \
    data_reserved/products/Окунь речной.tmp \
    data_reserved/products/Окунь речной.txt \
    data_reserved/products/Окунь холодного копчения(балычок).tmp \
    data_reserved/products/Окунь холодного копчения(балычок).txt \
    data_reserved/products/Оленина 1 категории.tmp \
    data_reserved/products/Оленина 1 категории.txt \
    data_reserved/products/Оливки консервированные.tmp \
    data_reserved/products/Оливки консервированные.txt \
    data_reserved/products/Опята свежие.tmp \
    data_reserved/products/Опята свежие.txt \
    data_reserved/products/Осетр.tmp \
    data_reserved/products/Осетр.txt \
    data_reserved/products/Отруби пшеничные.tmp \
    data_reserved/products/Отруби пшеничные.txt \
    data_reserved/products/Охотничьи колбаски п-копчёные.tmp \
    data_reserved/products/Охотничьи колбаски п-копчёные.txt \
    data_reserved/products/Паста ацидофильная нежирная.tmp \
    data_reserved/products/Паста ацидофильная нежирная.txt \
    data_reserved/products/Паста ацидофильная сладкая.tmp \
    data_reserved/products/Паста ацидофильная сладкая.txt \
    data_reserved/products/Паста яблочная с сахаром.tmp \
    data_reserved/products/Паста яблочная с сахаром.txt \
    data_reserved/products/Паста"Океан".tmp \
    data_reserved/products/Паста"Океан".txt \
    data_reserved/products/Пастернак (корень).tmp \
    data_reserved/products/Пастернак (корень).txt \
    data_reserved/products/Пастила.tmp \
    data_reserved/products/Пастила.txt \
    data_reserved/products/Патиссоны.tmp \
    data_reserved/products/Патиссоны.txt \
    data_reserved/products/Патока кукурузная.tmp \
    data_reserved/products/Патока кукурузная.txt \
    data_reserved/products/Пахта пастеризованная.tmp \
    data_reserved/products/Пахта пастеризованная.txt \
    data_reserved/products/Пахта сквашенная.tmp \
    data_reserved/products/Пахта сквашенная.txt \
    data_reserved/products/Паштет мясной.tmp \
    data_reserved/products/Паштет мясной.txt \
    data_reserved/products/Паштет печёночный.tmp \
    data_reserved/products/Паштет печёночный.txt \
    data_reserved/products/Пектин.tmp \
    data_reserved/products/Пектин.txt \
    data_reserved/products/Пельмени мясные.tmp \
    data_reserved/products/Пельмени мясные.txt \
    data_reserved/products/Перепёлки 1 категории.tmp \
    data_reserved/products/Перепёлки 1 категории.txt \
    data_reserved/products/Перец зелёный сладкий.tmp \
    data_reserved/products/Перец зелёный сладкий.txt \
    data_reserved/products/Перец красный сладкий.tmp \
    data_reserved/products/Перец красный сладкий.txt \
    data_reserved/products/Перловая.tmp \
    data_reserved/products/Перловая.txt \
    data_reserved/products/Персики.tmp \
    data_reserved/products/Персики.txt \
    data_reserved/products/Персиковый сок.tmp \
    data_reserved/products/Персиковый сок.txt \
    data_reserved/products/Петрушка (корень).tmp \
    data_reserved/products/Петрушка (корень).txt \
    data_reserved/products/Петрушка.tmp \
    data_reserved/products/Петрушка.txt \
    data_reserved/products/Печень говяжья.tmp \
    data_reserved/products/Печень говяжья.txt \
    data_reserved/products/Печень куриная .tmp \
    data_reserved/products/Печень куриная .txt \
    data_reserved/products/Печень свиная.tmp \
    data_reserved/products/Печень свиная.txt \
    data_reserved/products/Печенье миндальное.tmp \
    data_reserved/products/Печенье миндальное.txt \
    data_reserved/products/Печенье сахарное в-с.tmp \
    data_reserved/products/Печенье сахарное в-с.txt \
    data_reserved/products/Печенье сдобное.tmp \
    data_reserved/products/Печенье сдобное.txt \
    data_reserved/products/Пиво "Портер" 5%об..tmp \
    data_reserved/products/Пиво "Портер" 5%об..txt \
    data_reserved/products/Пиво жигулевское 2.8% об. .tmp \
    data_reserved/products/Пиво жигулевское 2.8% об. .txt \
    data_reserved/products/Пикша.tmp \
    data_reserved/products/Пикша.txt \
    data_reserved/products/Пирожное крошковое.tmp \
    data_reserved/products/Пирожное крошковое.txt \
    data_reserved/products/Пирожное миндальное.tmp \
    data_reserved/products/Пирожное миндальное.txt \
    data_reserved/products/Пирожное слоёное с кремом.tmp \
    data_reserved/products/Пирожное слоёное с кремом.txt \
    data_reserved/products/Пирожное трубочка с кремом .tmp \
    data_reserved/products/Пирожное трубочка с кремом .txt \
    data_reserved/products/Пирожное фруктовое.tmp \
    data_reserved/products/Пирожное фруктовое.txt \
    data_reserved/products/Пломбир крем-брюле.tmp \
    data_reserved/products/Пломбир крем-брюле.txt \
    data_reserved/products/Пломбир ореховый.tmp \
    data_reserved/products/Пломбир ореховый.txt \
    data_reserved/products/Пломбир шоколадный.tmp \
    data_reserved/products/Пломбир шоколадный.txt \
    data_reserved/products/Пломбир.tmp \
    data_reserved/products/Пломбир.txt \
    data_reserved/products/Плюшка московская.tmp \
    data_reserved/products/Плюшка московская.txt \
    data_reserved/products/Повидло яблочное.tmp \
    data_reserved/products/Повидло яблочное.txt \
    data_reserved/products/Подосиновики свежие.tmp \
    data_reserved/products/Подосиновики свежие.txt \
    data_reserved/products/Подосиновики сушеные.tmp \
    data_reserved/products/Подосиновики сушеные.txt \
    data_reserved/products/Подсолнечник (семена).tmp \
    data_reserved/products/Подсолнечник (семена).txt \
    data_reserved/products/Порошок горчичный.tmp \
    data_reserved/products/Порошок горчичный.txt \
    data_reserved/products/Почки говяжьи.tmp \
    data_reserved/products/Почки говяжьи.txt \
    data_reserved/products/Просо.tmp \
    data_reserved/products/Просо.txt \
    data_reserved/products/Простокваша Мечниковская.tmp \
    data_reserved/products/Простокваша Мечниковская.txt \
    data_reserved/products/Простокваша.tmp \
    data_reserved/products/Простокваша.txt \
    data_reserved/products/Пряники заварные.tmp \
    data_reserved/products/Пряники заварные.txt \
    data_reserved/products/Пунш "Чёрносмородиновый"17%об.tmp \
    data_reserved/products/Пунш "Чёрносмородиновый"17%об.txt \
    data_reserved/products/Пшеница мягкая озимая.tmp \
    data_reserved/products/Пшеница мягкая озимая.txt \
    data_reserved/products/Пшеница твёрдая.tmp \
    data_reserved/products/Пшеница твёрдая.txt \
    data_reserved/products/Пшеничная "Полтавская".tmp \
    data_reserved/products/Пшеничная "Полтавская".txt \
    data_reserved/products/Пшенная.tmp \
    data_reserved/products/Пшенная.txt \
    data_reserved/products/Пюре яблочное.tmp \
    data_reserved/products/Пюре яблочное.txt \
    data_reserved/products/Ревень (черешки).tmp \
    data_reserved/products/Ревень (черешки).txt \
    data_reserved/products/Редис.tmp \
    data_reserved/products/Редис.txt \
    data_reserved/products/Редька.tmp \
    data_reserved/products/Редька.txt \
    data_reserved/products/Репа.tmp \
    data_reserved/products/Репа.txt \
    data_reserved/products/Рис.tmp \
    data_reserved/products/Рис.txt \
    data_reserved/products/Рисовая.tmp \
    data_reserved/products/Рисовая.txt \
    data_reserved/products/Рожки обсыпные.tmp \
    data_reserved/products/Рожки обсыпные.txt \
    data_reserved/products/Рожь.tmp \
    data_reserved/products/Рожь.txt \
    data_reserved/products/Рыжики свежие.tmp \
    data_reserved/products/Рыжики свежие.txt \
    data_reserved/products/Рябина.tmp \
    data_reserved/products/Рябина.txt \
    data_reserved/products/Ряженка 6% жирности.tmp \
    data_reserved/products/Ряженка 6% жирности.txt \
    data_reserved/products/Сайра крупная.tmp \
    data_reserved/products/Сайра крупная.txt \
    data_reserved/products/Сайра мелкая.tmp \
    data_reserved/products/Сайра мелкая.txt \
    data_reserved/products/Салат.tmp \
    data_reserved/products/Салат.txt \
    data_reserved/products/Сардельки говяжьи.tmp \
    data_reserved/products/Сардельки говяжьи.txt \
    data_reserved/products/Сардельки свиные.tmp \
    data_reserved/products/Сардельки свиные.txt \
    data_reserved/products/Сахар-песок.tmp \
    data_reserved/products/Сахар-песок.txt \
    data_reserved/products/Сахар-рафинад.tmp \
    data_reserved/products/Сахар-рафинад.txt \
    data_reserved/products/Сахар-сырец.tmp \
    data_reserved/products/Сахар-сырец.txt \
    data_reserved/products/Свекла.tmp \
    data_reserved/products/Свекла.txt \
    data_reserved/products/Свекольный сок.tmp \
    data_reserved/products/Свекольный сок.txt \
    data_reserved/products/Свиная тазобедренная часть.tmp \
    data_reserved/products/Свиная тазобедренная часть.txt \
    data_reserved/products/Свинина вырезка.tmp \
    data_reserved/products/Свинина вырезка.txt \
    data_reserved/products/Свинина грудинка.tmp \
    data_reserved/products/Свинина грудинка.txt \
    data_reserved/products/Свинина жирная.tmp \
    data_reserved/products/Свинина жирная.txt \
    data_reserved/products/Свинина корейка.tmp \
    data_reserved/products/Свинина корейка.txt \
    data_reserved/products/Свинина мясная.tmp \
    data_reserved/products/Свинина мясная.txt \
    data_reserved/products/Свинина тушеная.tmp \
    data_reserved/products/Свинина тушеная.txt \
    data_reserved/products/Свиные ножки.tmp \
    data_reserved/products/Свиные ножки.txt \
    data_reserved/products/Сдоба выборгская с маком.tmp \
    data_reserved/products/Сдоба выборгская с маком.txt \
    data_reserved/products/Сельдерей (корень).tmp \
    data_reserved/products/Сельдерей (корень).txt \
    data_reserved/products/Сельдерей.tmp \
    data_reserved/products/Сельдерей.txt \
    data_reserved/products/Сельдь атлантическая солёная.tmp \
    data_reserved/products/Сельдь атлантическая солёная.txt \
    data_reserved/products/Сельдь жирная свежая.tmp \
    data_reserved/products/Сельдь жирная свежая.txt \
    data_reserved/products/Сельдь нежирная свежая.tmp \
    data_reserved/products/Сельдь нежирная свежая.txt \
    data_reserved/products/Сердце говяжье.tmp \
    data_reserved/products/Сердце говяжье.txt \
    data_reserved/products/Сердце куриное.tmp \
    data_reserved/products/Сердце куриное.txt \
    data_reserved/products/Скумбрия атлантическая.tmp \
    data_reserved/products/Скумбрия атлантическая.txt \
    data_reserved/products/Слива.tmp \
    data_reserved/products/Слива.txt \
    data_reserved/products/Сливки 10% жирности.tmp \
    data_reserved/products/Сливки 10% жирности.txt \
    data_reserved/products/Сливки 20% жирности.tmp \
    data_reserved/products/Сливки 20% жирности.txt \
    data_reserved/products/Сливки 35% жирности.tmp \
    data_reserved/products/Сливки 35% жирности.txt \
    data_reserved/products/Сливки взбитые плодовые.tmp \
    data_reserved/products/Сливки взбитые плодовые.txt \
    data_reserved/products/Сливки взбитые с шоколадом.tmp \
    data_reserved/products/Сливки взбитые с шоколадом.txt \
    data_reserved/products/Сливки сгущ. с сахаром.tmp \
    data_reserved/products/Сливки сгущ. с сахаром.txt \
    data_reserved/products/Сливки сухие высокожирные.tmp \
    data_reserved/products/Сливки сухие высокожирные.txt \
    data_reserved/products/Сливки сухие.tmp \
    data_reserved/products/Сливки сухие.txt \
    data_reserved/products/Сливовый сок.tmp \
    data_reserved/products/Сливовый сок.txt \
    data_reserved/products/Сливочное клубничное.tmp \
    data_reserved/products/Сливочное клубничное.txt \
    data_reserved/products/Сливочное крем-брюле.tmp \
    data_reserved/products/Сливочное крем-брюле.txt \
    data_reserved/products/Сливочное ореховое.tmp \
    data_reserved/products/Сливочное ореховое.txt \
    data_reserved/products/Сливочное шоколадное.tmp \
    data_reserved/products/Сливочное шоколадное.txt \
    data_reserved/products/Сметана 10% жирности.tmp \
    data_reserved/products/Сметана 10% жирности.txt \
    data_reserved/products/Сметана 20% жирности.tmp \
    data_reserved/products/Сметана 20% жирности.txt \
    data_reserved/products/Сметана 30% жирности.tmp \
    data_reserved/products/Сметана 30% жирности.txt \
    data_reserved/products/Сметана 40% жирности.tmp \
    data_reserved/products/Сметана 40% жирности.txt \
    data_reserved/products/Смородина белая.tmp \
    data_reserved/products/Смородина белая.txt \
    data_reserved/products/Смородина красная.tmp \
    data_reserved/products/Смородина красная.txt \
    data_reserved/products/Смородина чёрная.tmp \
    data_reserved/products/Смородина чёрная.txt \
    data_reserved/products/Снеток солено-сушеный.tmp \
    data_reserved/products/Снеток солено-сушеный.txt \
    data_reserved/products/Соломка сладкая.tmp \
    data_reserved/products/Соломка сладкая.txt \
    data_reserved/products/Соль поваренная.tmp \
    data_reserved/products/Соль поваренная.txt \
    data_reserved/products/Сосиски любительские.tmp \
    data_reserved/products/Сосиски любительские.txt \
    data_reserved/products/Сосиски молочные.tmp \
    data_reserved/products/Сосиски молочные.txt \
    data_reserved/products/Соус томатный острый.tmp \
    data_reserved/products/Соус томатный острый.txt \
    data_reserved/products/Соя.tmp \
    data_reserved/products/Соя.txt \
    data_reserved/products/Спаржа.tmp \
    data_reserved/products/Спаржа.txt \
    data_reserved/products/Ставрида океаническая.tmp \
    data_reserved/products/Ставрида океаническая.txt \
    data_reserved/products/Ставрида хол. копчения.tmp \
    data_reserved/products/Ставрида хол. копчения.txt \
    data_reserved/products/Судак.tmp \
    data_reserved/products/Судак.txt \
    data_reserved/products/Сухари армейские.tmp \
    data_reserved/products/Сухари армейские.txt \
    data_reserved/products/Сухари дорожные.tmp \
    data_reserved/products/Сухари дорожные.txt \
    data_reserved/products/Сухари сливочные в-с.tmp \
    data_reserved/products/Сухари сливочные в-с.txt \
    data_reserved/products/Сушки ванильные.tmp \
    data_reserved/products/Сушки ванильные.txt \
    data_reserved/products/Сушки горчичные.tmp \
    data_reserved/products/Сушки горчичные.txt \
    data_reserved/products/Сушки простые.tmp \
    data_reserved/products/Сушки простые.txt \
    data_reserved/products/Сыворотка подсырная.tmp \
    data_reserved/products/Сыворотка подсырная.txt \
    data_reserved/products/Сыворотка творожная.tmp \
    data_reserved/products/Сыворотка творожная.txt \
    data_reserved/products/Сыр "Вырусский".tmp \
    data_reserved/products/Сыр "Вырусский".txt \
    data_reserved/products/Сыр "Голландский".tmp \
    data_reserved/products/Сыр "Голландский".txt \
    data_reserved/products/Сыр "Пошехонский".tmp \
    data_reserved/products/Сыр "Пошехонский".txt \
    data_reserved/products/Сыр "Прибалтийский".tmp \
    data_reserved/products/Сыр "Прибалтийский".txt \
    data_reserved/products/Сыр "Рокфор".tmp \
    data_reserved/products/Сыр "Рокфор".txt \
    data_reserved/products/Сыр "Российский".tmp \
    data_reserved/products/Сыр "Российский".txt \
    data_reserved/products/Сыр колбасный копчёный.tmp \
    data_reserved/products/Сыр колбасный копчёный.txt \
    data_reserved/products/Сыр плавленый "Российский".tmp \
    data_reserved/products/Сыр плавленый "Российский".txt \
    data_reserved/products/Сырки глазированные.tmp \
    data_reserved/products/Сырки глазированные.txt \
    data_reserved/products/Сырки масса творожная.tmp \
    data_reserved/products/Сырки масса творожная.txt \
    data_reserved/products/Сырки творожные детские.tmp \
    data_reserved/products/Сырки творожные детские.txt \
    data_reserved/products/Творог жирный.tmp \
    data_reserved/products/Творог жирный.txt \
    data_reserved/products/Творог мягкий диетический.tmp \
    data_reserved/products/Творог мягкий диетический.txt \
    data_reserved/products/Творог нежирный.tmp \
    data_reserved/products/Творог нежирный.txt \
    data_reserved/products/Творог полужирный.tmp \
    data_reserved/products/Творог полужирный.txt \
    data_reserved/products/Творожная масса сладкая.tmp \
    data_reserved/products/Творожная масса сладкая.txt \
    data_reserved/products/Телятина 1 категории.tmp \
    data_reserved/products/Телятина 1 категории.txt \
    data_reserved/products/Толокно.tmp \
    data_reserved/products/Толокно.txt \
    data_reserved/products/Томат-пюре.tmp \
    data_reserved/products/Томат-пюре.txt \
    data_reserved/products/Томатная паста.tmp \
    data_reserved/products/Томатная паста.txt \
    data_reserved/products/Томатный сок.tmp \
    data_reserved/products/Томатный сок.txt \
    data_reserved/products/Томаты с кожицей.tmp \
    data_reserved/products/Томаты с кожицей.txt \
    data_reserved/products/Томаты.tmp \
    data_reserved/products/Томаты.txt \
    data_reserved/products/Торт с фруктовой начинкой.tmp \
    data_reserved/products/Торт с фруктовой начинкой.txt \
    data_reserved/products/Торт слоёный с кремом.tmp \
    data_reserved/products/Торт слоёный с кремом.txt \
    data_reserved/products/Треска горячего копчения.tmp \
    data_reserved/products/Треска горячего копчения.txt \
    data_reserved/products/Треска солёная.tmp \
    data_reserved/products/Треска солёная.txt \
    data_reserved/products/Треска.tmp \
    data_reserved/products/Треска.txt \
    data_reserved/products/Тунец.tmp \
    data_reserved/products/Тунец.txt \
    data_reserved/products/Тыква.tmp \
    data_reserved/products/Тыква.txt \
    data_reserved/products/Угорь.tmp \
    data_reserved/products/Угорь.txt \
    data_reserved/products/Укроп.tmp \
    data_reserved/products/Укроп.txt \
    data_reserved/products/Уксус 3%-ный.tmp \
    data_reserved/products/Уксус 3%-ный.txt \
    data_reserved/products/Урюк.tmp \
    data_reserved/products/Урюк.txt \
    data_reserved/products/Утки 1 категории.tmp \
    data_reserved/products/Утки 1 категории.txt \
    data_reserved/products/Фарш колбасный куриный.tmp \
    data_reserved/products/Фарш колбасный куриный.txt \
    data_reserved/products/Фарш свиной сосисочный.tmp \
    data_reserved/products/Фарш свиной сосисочный.txt \
    data_reserved/products/Фасоль (стручок).tmp \
    data_reserved/products/Фасоль (стручок).txt \
    data_reserved/products/Фасоль стручковая.tmp \
    data_reserved/products/Фасоль стручковая.txt \
    data_reserved/products/Фасоль.tmp \
    data_reserved/products/Фасоль.txt \
    data_reserved/products/Филе куриное.tmp \
    data_reserved/products/Филе куриное.txt \
    data_reserved/products/Финики.tmp \
    data_reserved/products/Финики.txt \
    data_reserved/products/Фундук.tmp \
    data_reserved/products/Фундук.txt \
    data_reserved/products/Халва подсолнечная.tmp \
    data_reserved/products/Халва подсолнечная.txt \
    data_reserved/products/Халва тахинная.tmp \
    data_reserved/products/Халва тахинная.txt \
    data_reserved/products/Хлеб бородинский.tmp \
    data_reserved/products/Хлеб бородинский.txt \
    data_reserved/products/Хлеб паляница.tmp \
    data_reserved/products/Хлеб паляница.txt \
    data_reserved/products/Хлеб пеклеванный.tmp \
    data_reserved/products/Хлеб пеклеванный.txt \
    data_reserved/products/Хлеб пшеничный зерновой.tmp \
    data_reserved/products/Хлеб пшеничный зерновой.txt \
    data_reserved/products/Хлеб пшеничный, 1 сорт.tmp \
    data_reserved/products/Хлеб пшеничный, 1 сорт.txt \
    data_reserved/products/Хлеб ржано-пшеничный.tmp \
    data_reserved/products/Хлеб ржано-пшеничный.txt \
    data_reserved/products/Хлеб ржаной формовой.tmp \
    data_reserved/products/Хлеб ржаной формовой.txt \
    data_reserved/products/Хрен.tmp \
    data_reserved/products/Хрен.txt \
    data_reserved/products/Хурма.tmp \
    data_reserved/products/Хурма.txt \
    data_reserved/products/Чай черный байховый.tmp \
    data_reserved/products/Чай черный байховый.txt \
    data_reserved/products/Чебурек.tmp \
    data_reserved/products/Чебурек.txt \
    data_reserved/products/Черемша.tmp \
    data_reserved/products/Черемша.txt \
    data_reserved/products/Черешня.tmp \
    data_reserved/products/Черешня.txt \
    data_reserved/products/Черника.tmp \
    data_reserved/products/Черника.txt \
    data_reserved/products/Черноплодная рябина.tmp \
    data_reserved/products/Черноплодная рябина.txt \
    data_reserved/products/Чернослив.tmp \
    data_reserved/products/Чернослив.txt \
    data_reserved/products/Черносмородиновый сок.tmp \
    data_reserved/products/Черносмородиновый сок.txt \
    data_reserved/products/Чеснок.tmp \
    data_reserved/products/Чеснок.txt \
    data_reserved/products/Чечевица.tmp \
    data_reserved/products/Чечевица.txt \
    data_reserved/products/Шампанское полусухое 12%об..tmp \
    data_reserved/products/Шампанское полусухое 12%об..txt \
    data_reserved/products/Шампиньоны свежие.tmp \
    data_reserved/products/Шампиньоны свежие.txt \
    data_reserved/products/Шелковица.tmp \
    data_reserved/products/Шелковица.txt \
    data_reserved/products/Шиповник свежий.tmp \
    data_reserved/products/Шиповник свежий.txt \
    data_reserved/products/Шиповник сухой.tmp \
    data_reserved/products/Шиповник сухой.txt \
    data_reserved/products/Шиповниковый сок.tmp \
    data_reserved/products/Шиповниковый сок.txt \
    data_reserved/products/Шоколад без добавлений.tmp \
    data_reserved/products/Шоколад без добавлений.txt \
    data_reserved/products/Шоколад молочный.tmp \
    data_reserved/products/Шоколад молочный.txt \
    data_reserved/products/Шоколад с орехами.tmp \
    data_reserved/products/Шоколад с орехами.txt \
    data_reserved/products/Шпик свиной (без шкурки).tmp \
    data_reserved/products/Шпик свиной (без шкурки).txt \
    data_reserved/products/Шпик свиной солёный.tmp \
    data_reserved/products/Шпик свиной солёный.txt \
    data_reserved/products/Шпинат-пюре.tmp \
    data_reserved/products/Шпинат-пюре.txt \
    data_reserved/products/Шпинат.tmp \
    data_reserved/products/Шпинат.txt \
    data_reserved/products/Щавель.tmp \
    data_reserved/products/Щавель.txt \
    data_reserved/products/Щука .tmp \
    data_reserved/products/Щука .txt \
    data_reserved/products/Эскимо.tmp \
    data_reserved/products/Эскимо.txt \
    data_reserved/products/Яблоки в сиропе.tmp \
    data_reserved/products/Яблоки в сиропе.txt \
    data_reserved/products/Яблоки зимние.tmp \
    data_reserved/products/Яблоки зимние.txt \
    data_reserved/products/Яблоки.tmp \
    data_reserved/products/Яблоки.txt \
    data_reserved/products/Яблочный сок.tmp \
    data_reserved/products/Яблочный сок.txt \
    data_reserved/products/Язык говяжий.tmp \
    data_reserved/products/Язык говяжий.txt \
    data_reserved/products/Язык свиной.tmp \
    data_reserved/products/Язык свиной.txt \
    data_reserved/products/Яичный порошок.tmp \
    data_reserved/products/Яичный порошок.txt \
    data_reserved/products/Яйцо куриное (белок).tmp \
    data_reserved/products/Яйцо куриное (белок).txt \
    data_reserved/products/Яйцо куриное (желток).tmp \
    data_reserved/products/Яйцо куриное (желток).txt \
    data_reserved/products/Яйцо куриное.tmp \
    data_reserved/products/Яйцо куриное.txt \
    data_reserved/products/Яйцо перепелиное .tmp \
    data_reserved/products/Яйцо перепелиное .txt \
    data_reserved/products/Ячменевая.tmp \
    data_reserved/products/Ячменевая.txt \
    data_reserved/products/Ячмень.tmp \
    data_reserved/products/Ячмень.txt \
    data_reserved/categories.txt
