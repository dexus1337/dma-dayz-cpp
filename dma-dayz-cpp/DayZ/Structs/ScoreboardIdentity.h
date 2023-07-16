#pragma once
#include "../../DMAMemoryManagement/includes.h";
#include "ArmaString.h"

namespace DayZ {
	class ScoreboardIdentity : public DMAMem::MemoryObject {

	public:

		uint32_t NetworkID;
		std::shared_ptr<ArmaString> PlayerName;

		ScoreboardIdentity() {
			this->registerOffset(0x30, &NetworkID, sizeof(uint32_t));

			PlayerName = std::shared_ptr<ArmaString>(new ArmaString());
			this->registerPointer(0xF0, PlayerName.get());
		}

		ScoreboardIdentity(DMAMem::VmmManager* vmmManager, DWORD remotePid, QWORD remoteAddress) : ScoreboardIdentity() {
			this->resolveOffsets(vmmManager, remotePid, remoteAddress);
		}
	};
}