
#include <windows.h>
LRESULT CALLBACK WinFun(HWND, UINT, WPARAM, LPARAM);
char WinName[]="Мое окно"; // Имя класса окна
int WINAPI WinMain(HINSTANCE hIns, HINSTANCE hPrevIns, LPSTR arg, int WinMode) {
HWND hwnd; // Дескриптор окна
MSG msg; // Содержит инф. о сообщении, посылаемом Windows WNDCLASSEX wcl; // Определяет класс окна
// Определение класса окна
wcl.hInstance=hIns; // Дескриптор данного экземпляра wcl.lpszClassName=WinName; //Имя класса
wcl.lpfnWndProc=WinFun; //Функция окна
wcl.style=0; //стиль по умолчанию
wcl.cbSize=sizeof(WNDCLASSEX); //Размер структуры wcl.hIcon=LoadIcon(NULL, IDI_APPLICATION); //Большая пиктограмма wcl.hIconSm=LoadIcon(NULL, IDI_WINLOGO); //Малая пиктограмма wcl.hCursor=LoadCursor(NULL, IDC_ARROW); //Форма курсора wcl.lpszMenuName=NULL; //Меню не используется
wcl.cbClsExtra=0; // Дополнительная информация отсутствует wcl.cbWndExtra=0;
// Фон окна задается белым wcl.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
// Регистрация класса окна
if (!RegisterClassEx(&wcl)) return 0;
// Создание окна
hwnd=CreateWindow(
              WinName, // Имя класса окна
              "Мое простое окно", // Заголовок
              WS_OVERLAPPEDWINDOW, // Стандартное окно
              CW_USEDEFAULT, // Координата X- определяется Windows
              CW_USEDEFAULT, // Координата Y- определяется Windows
              CW_USEDEFAULT, // ширина- определяется Windows
              CW_USEDEFAULT, // высота- определяется Windows
              HWND_DESKTOP, // Родительского окна нет
              NULL, // Меню нет
        hIns, // дескриптор данного экземпляра приложения
              NULL); // дополнительных аргументов нет
       // Отображение окна
       ShowWindow(hwnd, WinMode);
       UpdateWindow(hwnd);
       // Цикл сообщений
 
}
while(GetMessage(&msg, NULL, 0, 0))
{
TranslateMessage(&msg); // Разрешает использование клавиатуры DispatchMessage(&msg);
}
return msg.wParam;
// Эта функция вызывается Windows, которая передает ей сообщение
// из очереди сообщений
struct Line
{
       int x1, x2, y1, y2;
};
struct LineList // Список линий
{
       Line L;
       LineList *pNext;
};
LineList *pFirst=0, *p;
void add(LineList *&pF, LineList *p)
{ // Добавляем элемент в начало списка
       p->pNext=pF;
pF=p; }
int x1, x2, y1, y2;
HPEN pB, pW;
LRESULT CALLBACK WinFun(HWND hwnd, UINT message,
                                         WPARAM wParam, LPARAM lParam)
{
HDC hdc;
       PAINTSTRUCT ps;
       switch(message)
       {
       case WM_CREATE:
              pB=(HPEN)GetStockObject(BLACK_PEN);
pW=(HPEN)GetStockObject(WHITE_PEN);
       break;
case WM_RBUTTONDOWN:
       x2=x1=LOWORD(lParam);
       y2=y1=HIWORD(lParam);
       break;
case WM_MOUSEMOVE:
if (wParam & MK_RBUTTON) // Определяем нажата ли правая кнопка мыши {
              hdc=GetDC(hwnd);
              SelectObject(hdc, pW);
              MoveToEx(hdc, x1, y1, (LPPOINT)NULL);
              LineTo(hdc, x2, y2);
              x2=LOWORD(lParam);
           y2=HIWORD(lParam);
              SelectObject(hdc, pB);
              MoveToEx(hdc, x1, y1, (LPPOINT)NULL);
              LineTo(hdc, x2, y2);
              ReleaseDC(hwnd, hdc);
}
break;
case WM_RBUTTONUP: // Отпускаем правую кнопку мыши
       p=new LineList;
       p->L.x1=x1; p->L.x2=x2;
       p->L.y1=y1; p->L.y2=y2;
       add(pFirst, p);
       break;
case WM_PAINT: // Перерисовка
       hdc=BeginPaint(hwnd, &ps);
       p=pFirst;
       while(p)// Прсматриваем спикок и рисуем линии
       {
              MoveToEx(hdc, p->L.x1, p->L.y1, (LPPOINT)NULL);
              LineTo(hdc, p->L.x2, p->L.y2);
              p=p->pNext;
       }
       EndPaint(hwnd, &ps);
       break;
case WM_DESTROY: // Завершение программы
       PostQuitMessage(0);
break;
default:
// Позволяет Windows обрабатывать любые сообщения, // не указанные в предыдущем случае
return DefWindowProc(hwnd, message, wParam, lParam);
}
return 0; }
