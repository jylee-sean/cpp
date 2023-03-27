 
#include <memory>
#include <string>
#include <iostream>
#include <map>

class Resource {
public:
    Resource(const std::string& name, int size)
        : m_name(name), m_size(size) {}

    std::string getName() const { return m_name; }
    int getSize() const { return m_size; }

private:
    std::string m_name;
    int m_size;
};


class ResourceHolder {
public:
    std::shared_ptr<Resource> getResource(const std::string& name) {
        auto iter = m_resourceMap.find(name);
        if (iter != m_resourceMap.end()) {
            return iter->second;
        }
        else {
            // Load the resource from file
            std::shared_ptr<Resource> resource = std::make_shared<Resource>(name, 100);
            m_resourceMap[name] = resource;
            return resource;
        }
    }

private:
    std::map<std::string, std::shared_ptr<Resource>> m_resourceMap;
};


int main() {
    ResourceHolder resourceHolder;

    std::shared_ptr<Resource> res1 = resourceHolder.getResource("image1.png");
    std::shared_ptr<Resource> res2 = resourceHolder.getResource("sound1.wav");
    std::shared_ptr<Resource> res3 = resourceHolder.getResource("image1.png");

    std::cout << "Resource 1: " << res1->getName() << ", size: " << res1->getSize() << std::endl;
    std::cout << "Resource 2: " << res2->getName() << ", size: " << res2->getSize() << std::endl;
    std::cout << "Resource 3: " << res3->getName() << ", size: " << res3->getSize() << std::endl;
    std::cout << "res1 and res3 are " << (res1 == res3 ? "same" : "different") << std::endl;

    return 0;
}

