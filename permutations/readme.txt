На обычной while(next_permutation(s.begin(), s.end()) давай ошибки, поэтому решил выкручиваться как-то...
Считал количество перестановок как str.size()! / количество одинаковых букв и потом проверял есть уже такая перестановка
Прошло все тесты


upd:
нашел ошибку через while, нужно было просто сортировать строку, могло быть так:
sort(str.begin(), str.end());
vector<string> data;
do {
  data.push_back(str);
} while(next_permutation(str.begin(), str.end());
