

#ifndef DOOR_HEADER
#define DOOR_HEADER


#include "Entity.hpp"

namespace example
{
	class Door :public Entity
	{
	private:
		bool have_to_open = false;

		float speed = 5;

	public:

		Door(Scene * scene, btVector3 pos, btQuaternion rot)
			:Entity(scene, pos, rot)
		{
			std::shared_ptr<Rigidbody> body(new Rigidbody(pos, rot, std::shared_ptr<btBoxShape>(new btBoxShape(btVector3(0.1f, 1.0f, 1.0f))), Rigidbody::Type::STATIC));
			add_model("door", body, "../../assets/door.obj");
		}

		void update(float deltatime) override;

		void reset() override {}

		void open();
	};
}
#endif
