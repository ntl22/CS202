#include "loadingtask.hpp"

LoadingTask::LoadingTask(Context &context)
    : is_finished(false),
      thread(&LoadingTask::loadingTask, this),
      m_context(context) {}

void LoadingTask::launchTask()
{
    is_finished = false;
    thread.launch();
}

bool LoadingTask::isFinished() const
{
    return is_finished;
}

void LoadingTask::loadingTask()
{
    tmp.fonts->load(FONTS::IBMPlexMono, "./assets/fonts/IBMPlexMono.ttf");
    tmp.fonts->load(FONTS::Sansation, "./assets/fonts/Sansation.ttf");
    tmp.fonts->load(FONTS::visitor1, "./assets/fonts/visitor1.ttf");

    tmp.textures->load(TEXTURES::car, "./assets/images/car.png");
    tmp.textures->load(TEXTURES::cat1, "./assets/images/cat1.png");
    tmp.textures->load(TEXTURES::cat2, "./assets/images/cat2.png");
    tmp.textures->load(TEXTURES::cat3, "./assets/images/cat3.png");
    tmp.textures->load(TEXTURES::chicken, "./assets/images/chicken.png");
    tmp.textures->load(TEXTURES::lane1, "./assets/images/lane1.png");
    tmp.textures->load(TEXTURES::lane2, "./assets/images/lane2.png");
    tmp.textures->load(TEXTURES::lane3, "./assets/images/lane3.png");
    tmp.textures->load(TEXTURES::lane4, "./assets/images/lane4.png");
    tmp.textures->load(TEXTURES::lightGreen, "./assets/images/lightGreen.png");
    tmp.textures->load(TEXTURES::lightRed, "./assets/images/lightRed.png");
    tmp.textures->load(TEXTURES::peopleBack, "./assets/images/peopleBack.png");
    tmp.textures->load(TEXTURES::peopleFront, "./assets/images/peopleFront.png");
    tmp.textures->load(TEXTURES::peopleLeft, "./assets/images/peopleLeft.png");
    tmp.textures->load(TEXTURES::peopleRight, "./assets/images/peopleRight.png");
    tmp.textures->load(TEXTURES::player1, "./assets/images/player1.png");
    tmp.textures->load(TEXTURES::road, "./assets/images/road.png");
    tmp.textures->load(TEXTURES::truck, "./assets/images/truck.png");
    tmp.textures->load(TEXTURES::welcome_bg, "./assets/images/welcome_bg.png");

    tmp.sounds->load(SOUNDBUFFERS::jump, "./assets/sounds/jump.wav");
    tmp.sounds->load(SOUNDBUFFERS::cat, "./assets/sounds/cat.wav");
    tmp.sounds->load(SOUNDBUFFERS::chicken, "./assets/sounds/chicken.wav");
    tmp.sounds->load(SOUNDBUFFERS::car, "./assets/sounds/car.wav");
    tmp.sounds->load(SOUNDBUFFERS::light, "./assets/sounds/light.wav");
    tmp.sounds->load(SOUNDBUFFERS::levelup, "./assets/sounds/levelup.wav");
    tmp.sounds->load(SOUNDBUFFERS::finish, "./assets/sounds/finish.wav");

    tmp.musics->load(MUSICS::intro, "./assets/sounds/intro.wav");
    tmp.musics->load(MUSICS::playing, "./assets/sounds/game.flac");

    mutex.lock();
    m_context.fonts = std::move(tmp.fonts);
    m_context.textures = std::move(tmp.textures);
    m_context.sounds = std::move(tmp.sounds);
    m_context.musics = std::move(tmp.musics);

    is_finished = true;
    mutex.unlock();
}
