const submenus = [
    ["sub11", "sub12", "sub13"],
    ["sub21", "sub22", "sub23", "sub24"],
    ["sub31", "sub32", "sub33", "sub34", "sub35"],
    ["sub41", "sub42", "sub43", "sub44"],
    ["sub51", "sub52", "sub53", "sub54", "sub55"]
]

showSubmenu = function(id) {
    const submenucontainer = document.querySelector(".submenu-container .submenu-list");
    submenucontainer.innerHTML = "";
    submenus[id-1].forEach(submenu => {
        const li = document.createElement("div");
        li.classList.add("submenu-item");
        li.innerHTML = submenu;
        submenucontainer.appendChild(li);
    }) 
}


clearSubmenus = function() {
    document.querySelector(".submenu-container .submenu-list").innerHTML = ""
}