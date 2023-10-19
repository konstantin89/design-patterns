#include <iostream>
#include <memory>
#include <cstring>
#include <unordered_map>

// Reference - https://refactoring.guru/design-patterns/flyweight

// Problem - You have shooting game. Every bullet has sprite (image) that is relatively large in size. 
// If every bullet object has sprite object in it RAM usage will explode (1KB for each sprite times number of bullets).
//
// Solution - Each bullet has extrinsic (repeating) data like the bullet sprite.
//            Each bullet has intrinsic (unique) data like location, speed etc.
//            All GUN_BULLETs have same image so many bullets share same sprite.
//
//            We should store in bullets only unique data, and the repeating data should
//            be stored outside of the object and shared between all the GUN_BULLETs.
//
// In the example below we implement this design pattern.
// See that "std::unordered_map<BulletTypes, std::shared_ptr<SpriteInterface>> mSprites" is the repeating shared 
// data. We create only one GUN_BULLET sprite and share it between all GUN_BULLET instances. 
//
//
// std output example:
// ./app
// Creating GUN_BULLET sprite                         <------ Sprite is created only once!
// Creating GUN_BULLET bullet object
// GunBullet::Draw() is calling Sprite::Draw()
// GunBulletSprite::Draw()
// Creating GUN_BULLET bullet object
// GunBullet::Draw() is calling Sprite::Draw()
// GunBulletSprite::Draw()


enum BulletTypes
{
    GUN_BULLET = 0
};

class SpriteInterface
{
public:
    virtual void Draw() = 0;
};

// Sprite is large object that each Game bullet has.
// Since many bullets share few sprites, we don't need to have Sprite instance
// in each bullet.
class GunBulletSprite : public SpriteInterface
{
private:
    static constexpr int BUFFER_SIZE = 1000;
    std::unique_ptr<char[]> mHeavyData;

public:
    GunBulletSprite()
    {
        mHeavyData = std::make_unique<char[]>(GunBulletSprite::BUFFER_SIZE);
        std::memset(mHeavyData.get(), 0, GunBulletSprite::BUFFER_SIZE);
    }

    void Draw() override
    {
        std::cout << "GunBulletSprite::Draw()" << std::endl;
    }
};

class BulletInterface
{
protected: 
    std::shared_ptr<SpriteInterface> mSprite;

    int xLocation;
    int yLocation;

    BulletInterface(std::shared_ptr<SpriteInterface> sprite): mSprite(sprite)
    {
        xLocation = 0;
        yLocation = 0;
    }

public:
    virtual void Draw() = 0;

};

class GunBullet : public BulletInterface
{
public:
    GunBullet(std::shared_ptr<SpriteInterface> sprite) : BulletInterface(sprite) {}

    void Draw() override
    {
        std::cout << "GunBullet::Draw() is calling Sprite::Draw()" << std::endl;
        mSprite->Draw();
    }
};

class SpriteFactory
{
public:
    static std::shared_ptr<SpriteInterface> CreateBullet(BulletTypes type)
    {
        switch(type)
        {
            case GUN_BULLET:
                std::cout << "Creating GUN_BULLET sprite" << std::endl;
                return std::make_shared<GunBulletSprite>();

            default:
                return NULL;

        }
    }
};

class BulletFactory
{
public:

    std::shared_ptr<BulletInterface> CreateBullet(BulletTypes type)
    {
        if (mSprites.end() == mSprites.find(type))
        {
            // We create only one sprite for each bullet type and share it.
            mSprites[type] = SpriteFactory::CreateBullet(type);
        }

        switch(type)
        {
            case GUN_BULLET:
                std::cout << "Creating GUN_BULLET bullet object" << std::endl;

                // All GUN_BULLET bullets will share the same mSprites[GUN_BULLET] object.
                return std::make_shared<GunBullet>(mSprites[GUN_BULLET]);
            default:
                return NULL;
        }
    }

private:
    std::unordered_map<BulletTypes, std::shared_ptr<SpriteInterface>> mSprites;

};

int main()
{
    BulletFactory bulletFactory;

    auto gunBullet1 = bulletFactory.CreateBullet(GUN_BULLET);
    gunBullet1->Draw();
    
    auto gunBullet2 = bulletFactory.CreateBullet(GUN_BULLET);
    gunBullet2->Draw();

    return 0;
}