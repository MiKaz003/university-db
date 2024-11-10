university-db

Napiszcie od zera program, który będzie akademicką "bazą danych".

Używajcie STLa!
Wymagania (16 XP):

1.Przechowywanie rekordów studentów o strukturze: Imię, nazwisko, adres, nr indeksu, PESEL, płeć -DONE
2.Dodawanie nowych studentów - DONE
3.Wyświetlanie całej bazy danych - DONE
4.Wyszukiwanie po nazwisku - DONE
5.Wyszukiwanie po numerze PESEL - DONE
6.Sortowanie po numerze PESEL - DONE
7.Sortowanie po nazwisku - DONE
8.Usuwanie po numerze indeksu - DONE

university-db
Opcjonalne wymagania (12 XP):

    Walidacja czy numer PESEL jest poprawny Wiki - poprawność PESEL (trudne)
    Wczytywanie z pliku i zapisywanie całej bazy w pliku (trudne)

Organizacja

Zorganizujcie się w grupy 3-4 osobowe.

Tym razem zaczynacie projekt od zera. Sami musicie założyć sobie na niego repozytorium i dogadać się co do podziału prac. Nie będzie to łatwe, bo zadania są zależne od siebie 😉

Do podziału zadań i śledzenia statusu możecie wykorzystać zakładkę Projects na GitHubie w utworzonym przez siebie repo. Możecie skonfigurować go z szablonu Automated kanban with reviews.
Planning

Rozpocznijcie planowaniem, na którym utworzycie karteczki na każde zadanie w kolumnie To Do. Najlepiej przekonwertować je na Issues (może to wymagać włączenia Issues w Settings). Dzięki temu można przypisywać się do zadań i pisać w nich komentarze. Napiszcie też przy każdym zadaniu na ile dni pracy je szacujecie. Po zakończonym planningu wyślijcie proszę na kanale #university-db linka do waszej tablicy projektowej na GitHubie.
Daily

Podczas prac na bieżąco aktualizujcie zadania. Każdego dnia o stałej porze synchronizujecie się i mówicie jakie macie problemy.

Przy okazji, tak wygląda standardowe daily w przeciętnym korpo 😄
Code Review

Każde dostarczenie zadania/wymagania musi być poprzedzone Code Review innej osoby z zespołu (lub najlepiej kilku), aby zachować spójność i współdziałanie całości.
Testy

Tym razem testy musicie napisać sami. Ale spokojnie, nie wymagamy jeszcze pisania ich we frameworku GTest lub Catch2 (chociaż jeśli chcecie to śmiało!).

Wystarczy, że w funkcji main() użyjecie każdej zaimplementowanej przez was funkcji.

Testy będą polegały na sprawdzeniu zawartości bazy danych po poszczególnych operacjach. Najlepiej dopisać funkcję, która zwraca całą kolekcję studentów, aby po każdej operacji sprawdzać, czy jej zawartość jest taka jak oczekiwano.
Ocenianie

Gdy skończycie napiszcie na kanale #university-db i oznaczcie mnie (@Lukin-2054). Punkty będę przyznawał manualnie po osobistym code review :) Zastrzegam sobie jednak długi czas na sprawdzenie wszystkiego.

Możliwe że pierwsze review zrobię dopiero w lipcu!

Ale review kodu może zrobić absolutnie każdy! Śmiało komentujcie rozwiązania innych grup!