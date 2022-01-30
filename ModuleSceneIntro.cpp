#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));


	//Sensor

	sensor[0].SetPos(-28, 0, 112);
	sensor[0].size.x = 5;
	sensor[0].size.y = 2;
	sensor[0].size.z = 12;
	sensor[0].axis = false;
	sensor[0].wire = true;
	sensor[0].color.Set(225, 225, 0);
	physSensor = App->physics->AddBody(sensor[0], 0);
	physSensor->SetAsSensor(true);
	physSensor->SetId(2);
	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	for (p2List_item<Cube*>* current_building = box.getFirst(); current_building != nullptr; current_building = current_building->next) {
		current_building->data->Render();
	}
	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

