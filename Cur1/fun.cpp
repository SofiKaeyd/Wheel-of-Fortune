/*
**************************************************************
Модуль fun.сpp
гр. П22
Разработчик: Баглаева С. А.
Модифицирован: 10 июня 2025
--------------------------------------------------------------
Модуль окна входа
**************************************************************
*/

#include "MyForm.h"
#include "Quetions.h"
#include "Rating_Table.h"
#include "Authotization.h"
#include "UserClasses.h"
#include "fun.h"

// Считывание из файла данных игрока по nickname
ratingTable GetPlayerByNickname(System::String^ searchNickname, int check) {
	ratingTable player;
	std::string searchNickStr = marshal_as<std::string>(searchNickname);

	std::ifstream fin("PlayerResults.txt");
	if (!fin.is_open()) 
	{
		if (check == 1) {
			MessageBox::Show("Ошибка открытия файла!", "Ошибка", 
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {
			MessageBox::Show("File opening error!", "Error", 
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		return player;
	}

	std::string idStr, fileNick, scoreStr, correctAnswersStr, markStr;

	while (true) 
	{
		if (!std::getline(fin, idStr)) break;
		if (idStr.empty()) continue;
		if (!std::getline(fin, fileNick)) break;
		if (!std::getline(fin, scoreStr)) break;
		if (!std::getline(fin, correctAnswersStr)) break;
		if (!std::getline(fin, markStr)) break;

		std::string emptyLine;
		std::getline(fin, emptyLine);

		if (fileNick == searchNickStr) 
		{
			player.id = Convert::ToInt32(marshal_as<String^>(idStr));
			player.nickname = fileNick;
			player.score = Convert::ToInt32(marshal_as<String^>(scoreStr));
			player.correctAnswers = Convert::ToInt32(marshal_as<String^>(correctAnswersStr));
			player.mark = Convert::ToInt32(marshal_as<String^>(markStr));
			break;
		}
	}
	fin.close();
	return player;
}

// Считывание из файла данных об id по nickname
int GetPlayerIdByNickname(System::String^ searchNickname, int check) {
	std::string searchNickStr = msclr::interop::marshal_as<std::string>(searchNickname);
	int foundId = 0;

	std::ifstream fin("PlayerResults.txt");
	if (!fin.is_open()) 
	{
		if (check == 1) {
			MessageBox::Show("Ошибка открытия файла!", "Ошибка", 
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {
			MessageBox::Show("File opening error!", "Error", 
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		return foundId;
	}

	int id, score, correctAnswers, mark;
	std::string fileNick;

	while (fin >> id >> fileNick >> score >> correctAnswers >> mark)
	{
		if (fileNick == searchNickStr)
		{
			foundId = id;
			break;
		}
	}
	fin.close();
	return foundId;
}

// Считывание из файла записи максимального id
int ReadMaxIdFromFile(std::string filePath) {
	int maxId = 0;
	std::ifstream fIn(filePath);
	if (!fIn.is_open())	return maxId;

	int id = 0;
	std::string nickname;
	int score, correctAnswers, mark;

	// Читаем файл, ожидая 5 полей в каждой строке
	while (fIn >> id >> nickname >> score >> correctAnswers >> mark) 
	{
		if (id > maxId) 
		{
			maxId = id;
		}
	}
	fIn.close();

	return maxId;
}

// Считывание названия изображения из файла
String^ ReadWheelImageFromFile(std::string FilePath) {
	String^ whellImage = "multicolored";
	std::ifstream fOut(FilePath);
	if (!fOut.is_open())
	{
		return whellImage;
	}

	std::string temp;
	if (!(fOut >> temp)) {
		fOut.close();
		return whellImage;
	}

	fOut.close();
	whellImage = marshal_as<String^>(temp);
	return whellImage;
}

// Запись названия изображения в файл
void SaveWheelImageToFile(std::string FilePath, String^ whellImage) {
	std::ofstream fout(FilePath);
	if (!fout.is_open())
	{
		return;
	}
	marshal_context^ context = gcnew marshal_context();
	fout << context->marshal_as< std::string >(whellImage);

	fout.close();
}

// Считывание времени QuetionForm из файла
int ReadTimeQustionToFile(std::string FilePath, int check) {
	int timeQuestion = 90;
	std::ifstream fIn(FilePath);
	if (!fIn.is_open()) 
	{
		if (check == 1) {
			MessageBox::Show("Ошибка открытия файла!", "Ошибка", 
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {
			MessageBox::Show("File opening error!", "Error", 
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		return timeQuestion;
	}
	if (!(fIn >> timeQuestion)) 
	{
		fIn.close();
		return timeQuestion;
	}
	if (timeQuestion < 5) 
	{
		timeQuestion = 90;
	}

	fIn.close();
	return timeQuestion;
}

// Запись времени QuetionForm в файл
void SaveTimeQustionToFile(std::string FilePath, float timeQuestion, int check) {
	std::ofstream fout(FilePath);
	if (!fout.is_open()) 
	{
		if (check == 1) {
			MessageBox::Show("Ошибка открытия файла!", "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {
			MessageBox::Show("File opening error!", "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		return;
	}
	fout << timeQuestion;

	fout.close();
	if (check == 1) {
		MessageBox::Show("Таймер изменён!", "Таймер",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	else {
		MessageBox::Show("The timer has been changed!", "Timer",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}

// Удаление старых записей с повторяющимся nickname
void SavePlayerResults(String^ filePath, Player^ player) {
	msclr::interop::marshal_context context;
	std::string nowFilePath = context.marshal_as<std::string>(filePath);
	int currentId = player->id;
	std::string currentNickname = context.marshal_as<std::string>(player->nickname);

	std::ofstream fTemp("temp.txt"); // Временный файл
	std::ifstream fIn(nowFilePath);
	std::string line;

	bool isFirst = true;

	while (std::getline(fIn, line)) 
	{ // Фильтрация записей
		std::string idStr = line;
		std::string fileNickname;
		std::string scoreStr;
		std::string correctAnswersStr;
		std::string markStr;

		if (!std::getline(fIn, fileNickname) ||
			!std::getline(fIn, scoreStr) ||
			!std::getline(fIn, correctAnswersStr) ||
			!std::getline(fIn, markStr)) 
		{ // Для предотващения ошибки, если записи неверные
			break; 
		}

		std::getline(fIn, line); // Пропуск пустой строки

		if (fileNickname != currentNickname) 
		{
			if (!isFirst) fTemp << std::endl;
			fTemp << idStr << std::endl
				<< fileNickname << std::endl
				<< scoreStr << std::endl
				<< correctAnswersStr << std::endl
				<< markStr << std::endl;
			isFirst = false;
		}
	}

	if (!isFirst) fTemp << std::endl;
	fTemp << currentId << std::endl
		<< currentNickname << std::endl
		<< player->score << std::endl
		<< player->correctAnswers << std::endl
		<< player->mark << std::endl;

	fIn.close();
	fTemp.close();

	std::remove(nowFilePath.c_str());
	std::rename("temp.txt", nowFilePath.c_str());
}

// Проверка уникальности логина
bool IsnicknameUnique(const std::string& filePath, const std::string& nickname) {
	std::ifstream bin(filePath, std::ios::binary);
	if (!bin) return true;

	while (true) 
	{
		// Чтение размера логина
		size_t nicknameSize;
		bin.read((char*)&nicknameSize, sizeof(nicknameSize));

		// Проверка на конец файла/ошибку после чтения
		if (bin.eof() || bin.fail()) break;

		// Чтение логина
		std::string origNickname(nicknameSize, '\0');
		bin.read(&origNickname[0], nicknameSize);
		if (bin.fail()) break;

		// Пропуск пароля
		size_t passwordSize;
		bin.read((char*)&passwordSize, sizeof(passwordSize));
		if (bin.fail()) break;

		bin.seekg(passwordSize, std::ios::cur);
		if (bin.fail()) break;

		// Проверка совпадения
		if (origNickname == nickname) 
		{
			bin.close();
			return false;
		}
	}

	bin.close();
	return true;
}

// Сохранение в бинарный файл
void SaveToBinaryFile(std::string filePath, std::string filePathfor2Check, System::String^ text1, System::String^ text2, int check) {
	std::string nickname = msclr::interop::marshal_as<std::string>(text1);
	std::string password = msclr::interop::marshal_as<std::string>(text2);

	// Проверка уникальности логина в используемом файле
	if (!IsnicknameUnique(filePath, nickname)) 
	{
		if (check == 1) {
			MessageBox::Show("Логин должен быть уникальным!",
				"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {
			MessageBox::Show("The login must be unique!",
				"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		return;
	}

	// Проверка уникальности логина во втором файле
	if (!IsnicknameUnique(filePathfor2Check, nickname))
	{
		if (check == 1) {
			MessageBox::Show("Логин должен быть уникальным!",
				"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {
			MessageBox::Show("The login must be unique!",
				"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		return;
	}

	// Запись в файл
	std::ofstream bin(filePath, std::ios::binary | std::ios::app);
	if (bin) 
	{
		// Запись логина
		size_t nicknameSize = nickname.size();
		bin.write((const char*)&nicknameSize, sizeof(nicknameSize));
		bin.write(nickname.c_str(), nicknameSize);

		// Запись пароля
		size_t passwordSize = password.size();
		bin.write((const char*)&passwordSize, sizeof(passwordSize));
		bin.write(password.c_str(), passwordSize);

		bin.close();
		
		if (check == 1) {
			MessageBox::Show("Вы успешно зарегистрировались!",
				"Успешно", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			MessageBox::Show("You have successfully registered!",
				"Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	else 
	{
		if (check == 1) {
			MessageBox::Show("Ошибка открытия файла!", "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {
			MessageBox::Show("File opening error!", "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}

// Проверка авторизации
bool CheckAuthorization(std::string filePath, System::String^ text1, System::String^ text2) {
	std::ifstream bin(filePath, std::ios::binary);
    if (!bin.is_open()) return false;

    std::string nickname = msclr::interop::marshal_as<std::string>(text1);
    std::string password = msclr::interop::marshal_as<std::string>(text2);

    while (true) 
	{
        // Читение длины nickname
        size_t nicknameSize;
        if (!bin.read((char*)&nicknameSize, sizeof(nicknameSize))) break;

        // Читение nickname
        std::string fileNickname(nicknameSize, '\0');
		bin.read(&fileNickname[0], nicknameSize);

        // Читение длины password
        size_t passwordSize;
		bin.read((char*)&passwordSize, sizeof(passwordSize));

        // Читение password
        std::string filePassword(passwordSize, '\0');
		bin.read(&filePassword[0], passwordSize);

        if (fileNickname == nickname && filePassword == password) 
		{
			bin.close();
            return true;
        }
    }

	bin.close();
    return false;
}

// Подсчёт записей в файле
bool IsRecordLimitReached(std::string filename, int maxRecords) {
	std::ifstream file(filename);
	if (!file.is_open())
	{
		// Если файл не открылся, считаем, что записей пока нет.
		return false;
	}

	int lineCount = 0;
	std::string line;
	// Читаем весь файл и считаем строки
	while (std::getline(file, line))
	{
		lineCount++;
	}
	file.close();

	// Предполагается, что каждая запись занимает 3 строки
	int records = lineCount / 3;
	return (records >= maxRecords);
}

// Удаление всех элементов в файле
void ClearQuestionsFile(std::string filename) {
	std::ofstream ofs(filename, std::ios::trunc);
	ofs.close();
}

// Инициализация линейного однонаправленного списка
LISTratingTable* Init_List_RT(ratingTable xRT) {
	LISTratingTable* lst = new LISTratingTable; // выделение памяти под голову списка
	lst->element = xRT;
	lst->next = NULL; // это последний узел списка
	return lst; // голова списка
}

// Инициализация линейного однонаправленного списка
LISTQuetions* Init_List_Q(QuetionsStrct xQ) {
	LISTQuetions* lst = new LISTQuetions; // выделение памяти под голову списка
	lst->element = xQ;
	lst->next = NULL; // это последний узел списка
	return lst; // голова списка
}

// Вставка первого элемента в голову однонаправленного списка
LISTratingTable* InsFirst_List_RT(ratingTable xRT, LISTratingTable* LRT) {
	LISTratingTable* q = new LISTratingTable;
	q->element = xRT;
	q->next = LRT;
	return q;
}

// Вставка первого элемента в голову однонаправленного списка
LISTQuetions* InsFirst_List_Q(QuetionsStrct xQ, LISTQuetions* LQ) {
	LISTQuetions* q = new LISTQuetions;
	q->element = xQ;
	q->next = LQ;
	return q;
}

// Вставка элемента в конец списка
LISTratingTable* InsEnd_List_RT(ratingTable xRT, LISTratingTable* LRT) {
	LISTratingTable* q = new LISTratingTable;
	q->element = xRT;
	q->next = NULL;

	if (LRT == NULL) 
	{
		return q;  // если список пустой, новый элемент станет первым
	}

	LISTratingTable* temp = LRT;
	while (temp->next != NULL) 
	{
		temp = temp->next;  // идем до конца списка
	}
	temp->next = q;  // добавляем новый элемент в конец
	return LRT;
}

// Вставка элемента в конец списка
LISTQuetions* InsEnd_List_Q(QuetionsStrct xQ, LISTQuetions* LQ) {
	LISTQuetions* q = new LISTQuetions;
	q->element = xQ;
	q->next = NULL;

	if (LQ == NULL)
	{
		return q;  // если список пустой, новый элемент станет первым
	}

	LISTQuetions* temp = LQ;
	while (temp->next != NULL)
	{
		temp = temp->next;  // идем до конца списка
	}
	temp->next = q;  // добавляем новый элемент в конец
	return LQ;
}

// Удаление первого элемента из списка
LISTratingTable* DelFirst_List_RT(LISTratingTable* LRT) {
	if (LRT != nullptr) {
		LISTratingTable* temp = LRT;
		LRT = LRT->next;
		delete temp;
	}
	return LRT;
}

// Удаление первого элемента из списка
LISTQuetions* DelFirst_List_Q(LISTQuetions* LQ) {
	if (LQ != nullptr) {
		LISTQuetions* temp = LQ;
		LQ = LQ->next;
		delete temp;
	}
	return LQ;
}

// Удаление не первого элемента
LISTratingTable* Del_List_RT(LISTratingTable* LRT, LISTratingTable* p) {
	if (!LRT || !p) return LRT;

	if (LRT == p) // Если удаляется первый элемент
		return DelFirst_List_RT(LRT);

	LISTratingTable* current = LRT;	
	while (current->next != nullptr && current->next != p) { // Поиск узела, за которым следует p
		current = current->next;
	}
	if (current->next == p) {
		current->next = p->next;
		delete p;
	}
	return LRT;
}

// Удаление не первого элемента
LISTQuetions* Del_List_Q(LISTQuetions* LQ, LISTQuetions* p) {
	if (!LQ || !p) return LQ;

	if (LQ == p)
		return DelFirst_List_Q(LQ);

	LISTQuetions* current = LQ;
	while (current->next != nullptr && current->next != p) {
		current = current->next;
	}
	if (current->next == p) {
		current->next = p->next;
		delete p;
	}
	return LQ;
}

// Сохранение структуры ratingTable
void SavestRatingList(LISTratingTable* LRT, int check) {
	std::ofstream f("PlayerResults.txt");
	if (!f.is_open()) 
	{
		if (check == 1) {
			MessageBox::Show("Ошибка открытия файла!", "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {
			MessageBox::Show("File opening error!", "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		return;
	}
	LISTratingTable* q;
	q = LRT;
	while (q != NULL) {
		f << q->element.id << std::endl;
		f << q->element.nickname << std::endl;
		f << q->element.score << std::endl;
		f << q->element.correctAnswers << std::endl;
		f << q->element.mark << std::endl << std::endl;
		q = q->next;
	}
	f.close();
}

// Сохранение структуры QuetionsStrct
void SavestQuetionsStrct(LISTQuetions* LQ, int check) {
	std::ofstream f("Quetions.txt");
	if (!f.is_open()) 
	{
		if (check == 1) {
			MessageBox::Show("Ошибка открытия файла!", "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {
			MessageBox::Show("File opening error!", "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		return;
	}
	LISTQuetions* q;
	q = LQ;
	while (q != NULL) {
		f << q->element.num << std::endl;
		f << std::quoted(q->element.question) << std::endl;
		f << std::quoted(q->element.answer) << std::endl;
		q = q->next;
	}
	f.close();
}

// Поиск элемента x.id в однонаправленном списке
LISTratingTable* Find_id_List(LISTratingTable* LRT, ratingTable xRT) {
	LISTratingTable* q, * p = NULL; // дополнительный указатель
	// элемент не будет найден
	if (LRT != NULL) // если существует список
	{
		q = LRT;
		while ((q != NULL) && (q->element.id != xRT.id))
		{// пока не конец списка и не найден элемент
			q = q->next;
		}
		if (q != NULL) // если элемент найден
		{
			p = q;
		}
	}
	return p;
}

// Поиск элемента x.nickname в однонаправленном списке
LISTratingTable* Find_nickname_List(LISTratingTable* LRT, ratingTable xRT) {
	LISTratingTable* q, * p = NULL; // дополнительный указатель
	// элемент не будет найден
	if (LRT != NULL) // если существует список
	{
		q = LRT;
		while ((q != NULL) && (q->element.nickname != xRT.nickname))
		{// пока не конец списка и не найден элемент
			q = q->next;
		}
		if (q != NULL) // если элемент найден
		{
			p = q;
		}
	}
	return p;
}

// Поиск элемента x.score в однонаправленном списке
LISTratingTable* Find_score_List(LISTratingTable* LRT, ratingTable xRT) {
	LISTratingTable* q, * p = NULL; // дополнительный указатель
	// элемент не будет найден
	if (LRT != NULL) // если существует список
	{
		q = LRT;
		while ((q != NULL) && (q->element.score != xRT.score))
		{// пока не конец списка и не найден элемент
			q = q->next;
		}
		if (q != NULL) // если элемент найден
		{
			p = q;
		}
	}
	return p;
}

// Поиск элемента x.correctAnswers в однонаправленном списке
LISTratingTable* Find_correctAnswers_List(LISTratingTable* LRT, ratingTable xRT) {
	LISTratingTable* q, * p = NULL; // дополнительный указатель
	// элемент не будет найден
	if (LRT != NULL) // если существует список
	{
		q = LRT;
		while ((q != NULL) && (q->element.correctAnswers != xRT.correctAnswers))
		{// пока не конец списка и не найден элемент
			q = q->next;
		}
		if (q != NULL) // если элемент найден
		{
			p = q;
		}
	}
	return p;
}

// Поиск элемента x.mark в однонаправленном списке
LISTratingTable* Find_mark_List(LISTratingTable* LRT, ratingTable xRT) {
	LISTratingTable* q, * p = NULL; // дополнительный указатель
	// элемент не будет найден
	if (LRT != NULL) // если существует список
	{
		q = LRT;
		while ((q != NULL) && (q->element.mark != xRT.mark))
		{// пока не конец списка и не найден элемент
			q = q->next;
		}
		if (q != NULL) // если элемент найден
		{
			p = q;
		}
	}
	return p;
}

// Поиск элемента x.num в однонаправленном списке
LISTQuetions* Find_num_List_Q(LISTQuetions* LQ, QuetionsStrct xQ) {
	LISTQuetions* q, * p = NULL;
	if (LQ != NULL)	{
		q = LQ;
		while ((q != NULL) && (q->element.num != xQ.num))
		{
			q = q->next;
		}
		if (q != NULL)
		{
			p = q;
		}
	}
	return p;
}

// Сортировка id по убыванию
void Sort_id_1(LISTratingTable*& LRT) {
	if (LRT == nullptr || LRT->next == nullptr)
		return;

	LISTratingTable* sorted = nullptr;
	LISTratingTable* current = LRT;

	while (current != nullptr) {
		LISTratingTable* next = current->next;
		current->next = nullptr; // Открепление текущего элемента

		if (sorted == nullptr || current->element.id > sorted->element.id) {
			current->next = sorted;
			sorted = current;
		}
		else {
			LISTratingTable* p = sorted;
			while (p->next != nullptr && p->next->element.id >= current->element.id) {
				p = p->next;
			}
			current->next = p->next;
			p->next = current;
		}
		current = next;
	}
	LRT = sorted;
}

// Сортировка id по возрастанию
void Sort_id_2(LISTratingTable*& LRT) {
	if (LRT == nullptr || LRT->next == nullptr)
		return;

	LISTratingTable* sort = nullptr;
	LISTratingTable* current = LRT;

	while (current != nullptr) {
		LISTratingTable* next = current->next;
		current->next = nullptr;

		if (sort == nullptr || current->element.id < sort->element.id) {
			current->next = sort;
			sort = current;
		}
		else {
			LISTratingTable* p = sort;
			while (p->next != nullptr && p->next->element.id <= current->element.id) {
				p = p->next;
			}
			current->next = p->next;
			p->next = current;
		}
		current = next;
	}
	LRT = sort;
}

// Сортировка nickname по убыванию
void Sort_nickname_1(LISTratingTable* LRT) {
	if (LRT == nullptr || LRT->next == nullptr)
		return;
	bool flag = true;
	LISTratingTable* q = LRT;
	while (q->next) 
	{
		if ((q->element.nickname) < (q->next->element.nickname)) 
		{
			ratingTable tmp = q->next->element;
			q->next->element = q->element;
			q->element = tmp;
			Sort_nickname_1(LRT);
			flag = true;
		}
		else 
		{
			q = q->next;
		}
		if (flag == false) break;
	}
}

// Сортировка nickname по возрастанию
void Sort_nickname_2(LISTratingTable* LRT) {
	if (LRT == nullptr || LRT->next == nullptr)
		return;
	bool flag = true;
	LISTratingTable* q = LRT;
	while (q->next) 
	{
		if ((q->element.nickname) > (q->next->element.nickname)) 
		{
			ratingTable tmp = q->next->element;
			q->next->element = q->element;
			q->element = tmp;
			Sort_nickname_2(LRT);
			flag = true;
		}
		else 
		{
			q = q->next;
		}
		if (flag == false) break;
	}
}

// Сортировка score по убыванию
void Sort_score_1(LISTratingTable* LRT) {
	if (LRT == nullptr || LRT->next == nullptr)
		return;
	bool flag = true;
	LISTratingTable* q = LRT;
	while (q->next) 
	{
		if ((q->element.score) < (q->next->element.score)) 
		{
			ratingTable tmp = q->next->element;
			q->next->element = q->element;
			q->element = tmp;
			Sort_score_1(LRT);
			flag = true;
		}
		else 
		{
			q = q->next;
		}
		if (flag == false) break;
	}
}

// Сортировка score по возрастанию
void Sort_score_2(LISTratingTable* LRT) {
	if (LRT == nullptr || LRT->next == nullptr)
		return;
	bool flag = true;
	LISTratingTable* q = LRT;
	while (q->next) 
	{
		if ((q->element.score) > (q->next->element.score)) 
		{
			ratingTable tmp = q->next->element;
			q->next->element = q->element;
			q->element = tmp;
			Sort_score_2(LRT);
			flag = true;
		}
		else 
		{
			q = q->next;
		}
		if (flag == false) break;
	}
}

// Сортировка correctAnswers по убыванию
void Sort_correctAnswers_1(LISTratingTable*& LRT) {
	if (LRT == nullptr || LRT->next == nullptr)
		return;

	LISTratingTable* sorted = nullptr;
	LISTratingTable* current = LRT;

	while (current != nullptr) {
		LISTratingTable* next = current->next;
		current->next = nullptr; // Открепление текущего элемента

		if (sorted == nullptr || current->element.correctAnswers > 
			sorted->element.correctAnswers) {
			current->next = sorted;
			sorted = current;
		}
		else {
			LISTratingTable* p = sorted;
			while (p->next != nullptr && p->next->element.correctAnswers >= 
				current->element.correctAnswers) {
				p = p->next;
			}
			current->next = p->next;
			p->next = current;
		}
		current = next;
	}
	LRT = sorted;
}

// Сортировка correctAnswers по возрастанию
void Sort_correctAnswers_2(LISTratingTable*& LRT) {
	if (LRT == nullptr || LRT->next == nullptr)
		return;

	LISTratingTable* sorted = nullptr;
	LISTratingTable* current = LRT;

	while (current != nullptr) {
		LISTratingTable* next = current->next;
		current->next = nullptr; // Открепление текущего элемента

		if (sorted == nullptr || current->element.correctAnswers <
			sorted->element.correctAnswers) {
			current->next = sorted;
			sorted = current;
		}
		else {
			LISTratingTable* p = sorted;
			while (p->next != nullptr && p->next->element.correctAnswers <=
				current->element.correctAnswers) {
				p = p->next;
			}
			current->next = p->next;
			p->next = current;
		}
		current = next;
	}
	LRT = sorted;
}

// Сортировка mark по убыванию
void Sort_mark_1(LISTratingTable*& LRT) {
	if (LRT == nullptr || LRT->next == nullptr)
		return;

	LISTratingTable* sorted = nullptr;
	LISTratingTable* current = LRT;

	while (current != nullptr) {
		LISTratingTable* next = current->next;
		current->next = nullptr; // Открепление текущего элемента

		if (sorted == nullptr || current->element.mark > sorted->element.mark) {
			current->next = sorted;
			sorted = current;
		}
		else {
			LISTratingTable* p = sorted;
			while (p->next != nullptr && p->next->element.mark >= current->element.mark) {
				p = p->next;
			}
			current->next = p->next;
			p->next = current;
		}
		current = next;
	}
	LRT = sorted;
}

// Сортировка mark по возрастанию
void Sort_mark_2(LISTratingTable*& LRT) {
	if (LRT == nullptr || LRT->next == nullptr)
		return;

	LISTratingTable* sort = nullptr;
	LISTratingTable* current = LRT;

	while (current != nullptr) {
		LISTratingTable* next = current->next;
		current->next = nullptr;

		if (sort == nullptr || current->element.mark < sort->element.mark) {
			current->next = sort;
			sort = current;
		}
		else {
			LISTratingTable* p = sort;
			while (p->next != nullptr && p->next->element.mark <= current->element.mark) {
				p = p->next;
			}
			current->next = p->next;
			p->next = current;
		}
		current = next;
	}
	LRT = sort;
}

