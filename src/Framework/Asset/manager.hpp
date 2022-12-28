#ifndef SRC_FRAMEWORK_ASSET_MANAGER
#define SRC_FRAMEWORK_ASSET_MANAGER
#include <SFML/Audio/Music.hpp>

#include <cassert>
#include <map>
#include <memory>
#include <string>

template <typename Identifier, typename Asset>
class MediaMachine
{
public:
    typedef Identifier keyType;
    typedef Asset valueType;
    typedef std::unique_ptr<Asset> pointerType;

    MediaMachine() = default;

    void load(Identifier identifier, std::string path)
    {
        MediaMachine::pointerType ptr(new Asset());

        if (!ptr->loadFromFile(path))
            throw std::runtime_error("Assets_Management::load(): " + path + " load failed.");

        _insert(identifier, std::move(ptr));
    }

    template <typename Arg>
    void load(Identifier identifier, std::string path, Arg second)
    {
        MediaMachine::pointerType ptr(new Asset());

        if (!ptr->loadFromFile(path, second))
        {
            throw std::runtime_error("Assets_Management::load(): " + path + " load failed.");
        }

        _insert(identifier, std::move(ptr));
    }

    void loadMusic(Identifier identifier, std::string path)
    {
        MediaMachine::pointerType ptr(new Asset());

        if (!ptr->openFromFile(path))
        {
            throw std::runtime_error("Assets_Management::load(): " + path + " load failed.");
        }
        _insert(identifier, std::move(ptr));
    }

    Asset &get(Identifier identifier)
    {
        auto find = _machine.find(identifier);
        assert(find != _machine.end());
        return *find->second;
    }
    // const Asset &get(Identifier identifier) const
    // {
    //     auto find = _machine.find(identifier);
    //     assert(find != _machine.end());
    //     return *find->second;
    // }

private:
    void _insert(Identifier identifier, MediaMachine::pointerType resource)
    {
        auto insert = _machine.insert(std::make_pair(identifier, std::move(resource)));
        assert(insert.second);
    }

    std::map<Identifier, MediaMachine::pointerType> _machine;
};

#endif /* SRC_INCLUDE_ENGINE_ASSET_MANAGER */
