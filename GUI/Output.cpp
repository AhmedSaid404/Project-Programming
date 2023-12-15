#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.width = 1200;
	UI.height = 620;
	UI.wx = 15;
	UI.wy =15;

	UI.AppMode = DESIGN;	//Design Mode is the default mode

	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 80;
	UI.DrawingAreaWidth = 0.75 * UI.width;

	UI.DrawColor = BLUE;
	UI.HighlightColor = RED;
	UI.MsgColor = RED;

	UI.ASSGN_WDTH = 150;
	UI.ASSGN_HI = 50;

	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Programming Techniques Project");
	
	pWind->SetPen(RED,3);
	CreateDesignToolBar();
	CreateStatusBar();
	ClearDrawArea();
	ClearOutputBar();
}


Input* Output::CreateInput()
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y)
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar()
{
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
//TODO: Complete this function
void Output::CreateDesignToolBar() //Draws the Design Menu
{
	UI.AppMode = DESIGN;	//Design Mode
	
	//fill the tool bar 
		
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in Defs.h ==> enum DrawMenuItem
	string MenuItemImages[DSN_ITM_CNT];
	MenuItemImages[ITM_Start] = "images\\Start.jpg";
	MenuItemImages[ITM_End] = "images\\End.jpg";
	MenuItemImages[ITM_Read] = "images\\Read.jpg";
	MenuItemImages[ITM_Write] = "images\\Write.jpg";
	MenuItemImages[ITM_Ass_Value] = "images\\AssignValue.jpg";
	MenuItemImages[ITM_Ass_Variable] = "images\\AssignVariable.jpg";
	MenuItemImages[ITM_Ass_Operator] = "images\\AssignOperator.jpg";
	MenuItemImages[ITM_Condition] = "images\\Condition.jpg";
	MenuItemImages[ITM_Connector] = "images\\Connector.jpg";
	MenuItemImages[ITM_Select] = "images\\Select.jpg";
	MenuItemImages[ITM_Copy] = "images\\Copy.jpg";
	MenuItemImages[ITM_Paste] = "images\\Paste.jpg";
	MenuItemImages[ITM_Delete] = "images\\Delete.jpg";
	MenuItemImages[ITM_Simulation] = "images\\Simulation.jpg";
	MenuItemImages[ITM_Exit] = "images\\Exit.jpg";


	//TODO: Prepare images for each menu item and add it to the list


	//Draw menu item one image at a time
	for(int i=0; i<DSN_ITM_CNT; i++)
	pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
//TODO: Complete this function
void Output::CreateSimulationToolBar() //Draws the Simulation Menu
{
	UI.AppMode = SIMULATION;	//Simulation Mode
	///TODO: add code to create the simulation tool bar
	string MenuItemImages[SIM_ITM_CNT];
	MenuItemImages[ITM_Run] = "images\\Run.jpg";  
	MenuItemImages[ITM_Design] = "images\\Design.jpg";

	for (int i = 0; i < SIM_ITM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawArea()
{
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.DrawingAreaWidth, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearOutputBar()
{
	//Create output bar by drawing a filled rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(LIGHTBLUE);
	pWind->DrawRectangle(UI.DrawingAreaWidth, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::PrintMessage(string msg)	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int) (UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawString(const int iX, const int iY, const string Text)
{
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(iX, iY, Text);
}
//////////////////////////////////////////////////////////////////////////////////////////

//======================================================================================//
//								Statements Drawing Functions								//
//======================================================================================//

//Draw assignment statement and write the "Text" on it
void Output::DrawAssign(Point Left, int width, int height, string Text, bool Selected)
{
	if(Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor,3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor,3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawRectangle(Left.x, Left.y, Left.x + width, Left.y + height);
		
	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x+width/4, Left.y + height/4, Text);
}

//TODO: Add similar functions for drawing all other statements.
//		e.g. DrawCondtionalStat(......), DrawStart(......), DrawEnd(.......), ...etc
//		Decide the parameters that should be passed to each of them
	
// Draw Start statement function
void Output::DrawStart(Point Left, int width, int height, bool Selected) {

	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawEllipse(Left.x, Left.y, Left.x + width, Left.y + height);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 3, Left.y + height / 3, "Start");

}


// Draw End statement function

void Output:: DrawEnd(Point Left, int width, int height, bool Selected){      
	
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawEllipse(Left.x, Left.y, Left.x + width, Left.y + height);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 2.5, Left.y + height / 3, "End");

}
	
// Draw Condtinal statement function

void Output::DrawCondtinalStat(Point Left, int width, int height, string text, bool Selected) {

	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	int ipx[4] = { Left.x, Left.x + (width / 2) , Left.x + width , Left.x + (width / 2) };
	int ipy[4] = { Left.y, Left.y + (height / 2) , Left.y , Left.y - (height / 2) };

	pWind->DrawPolygon(ipx, ipy, 4);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 5, Left.y - height/5, text);

}


// Draw I/O statement function
void Output::DrawIOStat(Point Left, int width, int height, string text, bool Selected ) {

	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	int ipx[4] = { Left.x, Left.x + width , Left.x + (width - width/4) , Left.x - (width / 4) };
	int ipy[4] = { Left.y, Left.y  , Left.y + height , Left.y + height };

	pWind->DrawPolygon(ipx, ipy, 4);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 6, Left.y + height / 3, text);

}



//TODO: Add DrawConnector function


void Output:: DrawConnector(int ix1, int iy1, int ix2, int iy2, bool Selected) {

	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	if (ix1 == ix2 && iy2 > iy1) {                            //  if the distination point straight line under the starting point
		pWind->DrawLine(ix1, iy1, ix2, iy2);
		pWind->DrawTriangle(ix2, iy2, ix2 - 5, iy2 - 5, ix2 + 5, iy2 - 5);
	}

	if ((ix2 > ix1 || ix2 < ix1) && iy2>iy1){                   //  if the distination point under the starting point but not in straight line

		pWind->DrawLine(ix1, iy1, ix2, iy1);

		pWind->DrawLine(ix2, iy1, ix2, iy2);

		pWind->DrawTriangle(ix2, iy2, ix2 - 5, iy2 - 5, ix2 + 5, iy2 - 5);
	}

	if (ix1 == ix2 && iy2 < iy1) {                            //  if the distination point straight line above the starting point
		pWind->DrawLine(ix1, iy1, ix2, iy2);
		pWind->DrawTriangle(ix2, iy2, ix2 - 5, iy2 + 5, ix2 + 5, iy2 + 5);
	}
	
	if ((ix2 > ix1 || ix2 < ix1) && iy2<iy1) {                   //  if the distination point above the starting point but not in straight line

		pWind->DrawLine(ix1, iy1, ix2, iy1);

		pWind->DrawLine(ix2, iy1, ix2, iy2);

		pWind->DrawTriangle(ix2, iy2, ix2 - 5, iy2 + 5, ix2 + 5, iy2 + 5);
	}
	

}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}
