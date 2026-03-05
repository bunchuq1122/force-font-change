#include <Geode/Geode.hpp>
#include <Geode/utils/cocos.hpp>

using namespace geode::prelude;

#include <Geode/modify/CCLabelBMFont.hpp>
#include <filesystem>

class $modify(CCLabelBMFont) {
    static CCLabelBMFont* create(
        const char* str,
        const char* fntFile,
        float width,
        CCTextAlignment alignment,
        CCPoint imageOffset
    ) {

		auto fontPath =
            Mod::get()->getSettingValue<std::filesystem::path>("font-file");
		std::string pathstr = fontPath.string();

        if (std::string(fntFile) == "bigFont.fnt" || std::string(fntFile) == "goldFont.fnt") {
			if (Mod::get()->getSettingValue<bool>("customfnt") && !pathstr.empty()) {
				fntFile = pathstr.c_str();
			}else {
				fntFile = "gjFont44-hd.fnt";
			}
        }

        return CCLabelBMFont::create(str, fntFile, width, alignment, imageOffset);
    }
};