LittlerootTown_NewProfessorBirchsLab_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_NewProfessorBirchsLab_OnLoad
	.byte 0


LittlerootTown_NewProfessorBirchsLab_EventScript_Bookshelf::
	lockall
	compare VAR_SECRET_BUTTON, 1
	goto_if_ne LittlerootTown_NewProfessorBirchsLab_EventScript_Bookshelf_2
	msgbox LittlerootTown_NewProfessorBirchsLab_EventScript_Bookshelf_Text_2
LittlerootTown_NewProfessorBirchsLab_EventScript_Bookshelf_1:
	releaseall
	end

LittlerootTown_NewProfessorBirchsLab_EventScript_Bookshelf_2:
	msgbox LittlerootTown_NewProfessorBirchsLab_EventScript_Bookshelf_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LittlerootTown_NewProfessorBirchsLab_EventScript_Bookshelf_5
	msgbox LittlerootTown_NewProfessorBirchsLab_EventScript_Bookshelf_Text_1
	waitmessage
	goto LittlerootTown_NewProfessorBirchsLab_EventScript_Bookshelf_1

LittlerootTown_NewProfessorBirchsLab_EventScript_Bookshelf_5:
	call LittlerootTown_NewProfessorBirchsLab_EventScript_Yes
	goto LittlerootTown_NewProfessorBirchsLab_EventScript_Bookshelf_1


LittlerootTown_NewProfessorBirchsLab_OnLoad::
	compare VAR_SECRET_BUTTON, 1
	goto_if_eq LittlerootTown_NewProfessorBirchsLab_OnLoad_2
LittlerootTown_NewProfessorBirchsLab_OnLoad_1:
	end

LittlerootTown_NewProfessorBirchsLab_OnLoad_2:
	call LittlerootTown_NewProfessorBirchsLab_EventScript_OpenSecretRoom
	goto LittlerootTown_NewProfessorBirchsLab_OnLoad_1


LittlerootTown_NewProfessorBirchsLab_EventScript_Yes::
	setvar VAR_SECRET_BUTTON, 1
	msgbox LittlerootTown_NewProfessorBirchsLab_EventScript_Yes_Text_0
	waitmessage
	playse SE_BANG
	call LittlerootTown_NewProfessorBirchsLab_EventScript_OpenSecretRoom
	waitse
	msgbox LittlerootTown_NewProfessorBirchsLab_EventScript_Yes_Text_1
	waitmessage
	return


LittlerootTown_NewProfessorBirchsLab_EventScript_OpenSecretRoom::
	setmetatile 2, 6, 0x27D, TRUE
	setmetatile 2, 7, 0x283, FALSE
	setmetatile 3, 6, 0x22C, TRUE
	setmetatile 3, 7, 0x234, TRUE
	setmetatile 4, 6, 0x22D, TRUE
	setmetatile 4, 7, 0x235, TRUE
	setmetatile 4, 8, 0x23E, FALSE
	special DrawWholeMapView
	return


LittlerootTown_NewProfessorBirchsLab_BrokenDoorSign::
	lockall
	msgbox LittlerootTown_NewProfessorBirchsLab_BrokenDoorSign_Text_0
	releaseall
	end


LittlerootTown_NewProfessorBirchsLab_EventScript_Bookshelf_Text_0:
	.string "There is a lever behind\n one of the books.\p Do you want to flip it?$"

LittlerootTown_NewProfessorBirchsLab_EventScript_Bookshelf_Text_1:
	.string "You didn't flip the lever.$"

LittlerootTown_NewProfessorBirchsLab_EventScript_Bookshelf_Text_2:
	.string "The lever was already flipped.$"

LittlerootTown_NewProfessorBirchsLab_EventScript_Yes_Text_0:
	.string "You flipped the lever.$"

LittlerootTown_NewProfessorBirchsLab_EventScript_Yes_Text_1:
	.string "The bookshelf moved aside!$"

LittlerootTown_NewProfessorBirchsLab_BrokenDoorSign_Text_0:
	.string "This door looks demolished.\n It can't be opened$"
