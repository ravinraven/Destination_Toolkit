#ifndef MY_UI_TOO_IWIDGET_H
#define MY_UI_TOO_IWIDGET_H
#include "Utilities.h"
#include <set>

namespace MY_UI_Too{

	namespace Interfaces{

		class IWidget{
		public:

			IWidget();
			virtual ~IWidget();

			/*
			all control positions are specific in relative coordinates. Meaning relative to the top left corner of the Control Top Left.
			*/
			virtual void Set_Control_Bounds(Utilities::Rect p)=0;
			virtual Utilities::Rect Get_Control_Bounds()=0;

			virtual void Set_Control_Size(Utilities::Point p)=0;
			virtual Utilities::Point Get_Control_Size()=0;

			virtual void Set_Control_Pos(Utilities::Point p)=0;
			virtual Utilities::Point Get_Control_Pos()=0;

			/*
			all client positions are specific in relative coordinates. Meaning relative to the top left corner of the Control Top Left.
			*/
			virtual void Set_Client_Bounds(Utilities::Rect p)=0;
			virtual Utilities::Rect Get_Client_Bounds()=0;

			virtual void Set_Client_Size(Utilities::Point p)=0;
			virtual Utilities::Point Get_Client_Size()=0;

			virtual void Set_Client_Pos(Utilities::Point p)=0;
			virtual Utilities::Point Get_Client_Pos()=0;

			//Input functions
			virtual void Mouse_Left_Down()=0;
			virtual void Mouse_Left_Up()=0;
			virtual void Mouse_Right_Down()=0;
			virtual void Mouse_Right_Up()=0;
			virtual void Mouse_Moved()=0;
			virtual void Mouse_Entered()=0;
			virtual void Mouse_Exited()=0;
			virtual void Mouse_Wheel_Moved()=0;

			virtual void Key_Down()=0;
			virtual void Key_Up()=0;


			//Utility Functions
			virtual IWidget* Hit()=0;
			virtual IWidget* Hit_And_SetFocus()=0;

			virtual void Add(IWidget* child)=0;
			virtual void Remove(IWidget* child)=0;

			virtual void Set_Hidden(bool hidden)=0;
			virtual bool Get_Hidden()const =0;

			virtual void Set_Parent(IWidget* parent)=0;
			virtual IWidget* Get_Parent()const =0;

			virtual void Set_Focus(bool focus)=0;
			virtual bool Get_Focus() const =0;

			virtual void Set_Draggable(bool draggable)=0;
			virtual bool Get_Draggable() const =0;

			virtual void Set_Name(std::string name)=0;
			virtual std::string Get_Name()const =0;

			virtual void Draw()=0;
		};	
	};
	namespace Interfaces{
		class IRenderer;
		class ISkin;
		class IFont_Factory;
	};
	namespace Internal{

		extern std::set<MY_UI_Too::Interfaces::IWidget*> AllWidgets;
		extern MY_UI_Too::Interfaces::IWidget* Root_Widget;
		extern MY_UI_Too::Interfaces::IRenderer* Renderer;
		extern MY_UI_Too::Interfaces::ISkin* UI_Skin;
		extern MY_UI_Too::Interfaces::IFont_Factory* Font_Factory;
	};
	void Init(MY_UI_Too::Interfaces::IRenderer* renderer, MY_UI_Too::Interfaces::ISkin* skin, MY_UI_Too::Interfaces::IFont_Factory* fontfactory, MY_UI_Too::Interfaces::IWidget* root, unsigned int screen_width, unsigned int screen_height);
	void Safe_Delete(Interfaces::IWidget*& widget);
};


#endif