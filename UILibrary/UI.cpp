
#include "UI.h"
#include "PartsUtilsUI.h"
#include "MakeWidgetFeature.h"
#include "..\AppLibrary\PartOps.h"
#include "..\Journaling\Journaling.h"
#include "..\Core\LibraryLoad.h"

UI::UI()
{

}


void UI::Init()
{

}

void UI::StartGUILoop()
{

	// This is just mimic'ing a simple CAD workflow.
	// We are going to pretend the user makes  part, makes a widget feature, saves the part,
	// and then exits.  And this will stop the GUI loop and lead to exit on main

	//Setup Journaling File
	SetJournalingLangauge(JournalingLanguage::CPP);
	StartJournaling("C:\\Users\\polek\\source\\repos\\AutomationAPI_pt2\\JournaledCPPFileProject\\SampleJournal.txt");


	PartFile * partFile = MakePartUI("d:\\workdir\\someDir\\SomeName.part");
	AddWidgetFeatureToPartUI(partFile, true, 10);
	SavePartUI(partFile);

	PartFile* partFile2 = OpenPartUI("C:\\Users\\polek\\source\\repos\\AutomationAPI_pt2\\SampleVersionUp.prt");

	//End Journaling
	EndJournaling();

	std::cout << "Before Loaded Library"<<std::endl;
	HINSTANCE handle = LoadLibrary("COOLDEMANDLOADEDLIBRARY.dll");
	std::cout << "After Loaded Library"<<std::endl;
	UnloadLibrary(handle);
	std::cout << "After UnLoaded Library"<<std::endl;
	

}