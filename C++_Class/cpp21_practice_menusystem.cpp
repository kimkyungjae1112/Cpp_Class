#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
using namespace std;

#define clrscr() system("cls")
#define getkey() _getch()
namespace My_menu
{

	class AbstractMenu
	{
		string title;
	public:
		AbstractMenu(string s) : title(s) {}

		virtual ~AbstractMenu() {}

		string getTitle()
		{
			return title;
		}

		virtual void command() = 0;
	};

	class MenuItem : public AbstractMenu
	{
		int id;
	public:
		MenuItem(string s, int n) : AbstractMenu(s), id(n) {}

		virtual void command()
		{

			cout << getTitle() << " is selected." << endl;
			getkey();
		}
	};

	class PopupMenu : public AbstractMenu
	{
	private:
		vector<AbstractMenu*> v;

	public:
		PopupMenu(string s) : AbstractMenu(s) {}
		~PopupMenu()
		{
			for (int i = 0; i < v.size(); ++i)
			{
				delete v[i];
			}
		}

		void addMenu(AbstractMenu* p)
		{
			v.push_back(p);
		}

		virtual void command()
		{
			while (true)
			{
				clrscr();


				int size = v.size();

				for (int i = 0; i < size; ++i)
				{
					cout << i + 1 << ". " << v[i]->getTitle() << endl;
				}
				cout << size + 1 << ". << Back" << endl;

				cout << "Select an item >> ";
				int cmd;
				cin >> cmd;

				if (cmd == size + 1) break;
				if (cmd < 1 || cmd > size + 1) continue;
				v[cmd - 1]->command();
			}
		}
	};

	int main()
	{
		PopupMenu* menubar = new PopupMenu("MAIN");

		PopupMenu* p1 = new PopupMenu("캐릭터 선택");
		PopupMenu* p2 = new PopupMenu("이동");
		PopupMenu* p3 = new PopupMenu("사냥");

		menubar->addMenu(p1);
		menubar->addMenu(p2);
		menubar->addMenu(p3);

		p1->addMenu(new MenuItem("전사", 11));
		p1->addMenu(new MenuItem("마법사", 12));
		p1->addMenu(new MenuItem("궁수", 13));

		p2->addMenu(new MenuItem("해네시스", 21));
		p2->addMenu(new MenuItem("귀곡리", 22));

		p3->addMenu(new MenuItem("슬라임", 31));
		p3->addMenu(new MenuItem("개구리", 32));

		menubar->command();
		delete menubar;
		return 0;
	}
}