#ifndef SRC_FRAMEWORK_ASSET_MANAGER
#define SRC_FRAMEWORK_ASSET_MANAGER
#include <SFML/Audio/Music.hpp>

#include <cassert>
#include <stdexcept>
#include <map>
#include <memory>
#include <string>

template <typename Identifier, typename Asset>
class AssetMap
{
public:
    AssetMap() = default;
    virtual ~AssetMap() = default;

    void load(Identifier identifier, std::string path)
    {
        std::unique_ptr<Asset> ptr(new Asset());

        if (!ptr->loadFromFile(path))
            throw std::runtime_error("AssetMap::load(): " + path + " load failed.");

        insert(identifier, std::move(ptr));
    }

    Asset &get(Identifier identifier)
    {
        auto find = machine.find(identifier);
        if (find == machine.end())
            throw std::runtime_error("AssetMap::get(): Asset not found");
        return *find->second;
    }

    const Asset &get(Identifier identifier) const
    {
        auto find = _machine.find(identifier);
        if (find == machine.end())
            throw std::runtime_error("MediaMachine::get(): Asset not found");
        return *find->second;
    }

private:
    void insert(Identifier identifier, std::unique_ptr<Asset> resource)
    {
        auto insert = machine.insert(std::make_pair(identifier, std::move(resource)));
        assert(insert.second);
    }

    std::map<Identifier, std::unique_ptr<Asset>> machine;
};

#endif /* SRC_INCLUDE_ENGINE_ASSET_MANAGER */
