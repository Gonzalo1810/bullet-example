#ifndef ENTITY_BULLET_HEADER
#define ENTITY_BULLET_HEADER


#include <map>
#include <string>
#include <iostream>


#include "Scene.hpp"
#include "Rigidbody.hpp"
#include "SFML/Graphics.hpp"

#include <btBulletDynamicsCommon.h>
#include <Model_Obj.hpp>



using namespace std;

namespace example
{
	class Entity
	{
	protected:
		Scene * scene;

		btVector3 initial_position;
		btTransform transform;

		struct Model_Group
		{
			float scale = 1.f;
			std::shared_ptr<glt::Model> mesh;
			std::shared_ptr<Rigidbody> body;
		};

		//std::map<std::string, std::shared_ptr< Rigidbody>> bodies;
		std::map<std::string, Model_Group> models;
		std::map<std::string, std::shared_ptr<Sensor>> sensors;
		std::map<std::string, std::shared_ptr<btHingeConstraint>> joints;


	public:
		Entity(Scene * scene, btVector3 pos, btQuaternion rot)
			:scene(scene), initial_position(pos)
		{
			//transform.setIdentity();
			//transform.setOrigin(initial_position);
			//transform.setRotation(rot);
			initial_position = pos;
		}

		virtual ~Entity() {}

	public:
		virtual void update(float deltatime);

		virtual void reset() = 0;

	public:

		std::shared_ptr<Rigidbody> get_rigidbody(const std::string & name)
		{
			return models[name].body;
		}

		const btVector3 & get_current_position() const{ return transform.getOrigin(); }

		Scene * get_scene() const { return scene; }

		void add_model(const std::string & name, std::shared_ptr<Rigidbody> & rb, const std::string & path, float scale = 1.f);
	};
}

#endif
