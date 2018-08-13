<template>
  <div>
    <p>home</p>
    <router-link to="/devices">devicelist</router-link>
        <div class="preloader"></div>

    <section class="main">
        <div class="container">
            <div class="table">
                <div class="table_box">
                    <div class="left_column table_item">
                        <div class="row" data-row="row_1">Название:</div>
                        <div class="row" data-row="row_2">Общее время:</div>
                        <div class="row" data-row="row_3">Культура 1 линия:</div>
                        <div class="row" data-row="row_4">Культура 2 линия:</div>
                        <div class="row" data-row="row_5">Сорт 1 линия:</div>
                        <div class="row" data-row="row_6">Сорт 2 линия:</div>
                        <div class="row" data-row="row_7">Влажность 1 линия:</div>
                        <div class="row" data-row="row_8">Влажность 2 линия:</div>
                        <div class="row" data-row="row_9">Уровень воды:</div>
                        <div class="row" data-row="row_10">Температура воздуха:</div>
                        <div class="row" data-row="row_11">Влажность воздуха:</div>
                        <div class="row" data-row="row_12">Расход электроэнергии:</div>
                        <div class="row" data-row="row_13">Уровень PH <input type="button" class="measure" data-name="Уровень PH" value="Измерить"></div>
                        <div class="row" data-row="row_14">Уровень TDS <input type="button" class="measure" data-name="Уровень TDS" value="Измерить"></div>
                        <div class="row" data-row="row_15">Фото:</div>
                        <div class="row" data-row="row_16">Комментарий:</div>
                    </div>
                    <div class="table_content table_item" id="table_content">
                        <div class="column">
                            <div class="row" data-row="row_1">
                                <button class="button top change_name"><img src="img/comment_img.png" alt=""></button>
                                <a href="/statistics" class="button bottom statistics_open"><img src="img/statistics_img.png" alt=""></a> Устройство 1
                            </div>
                            <div class="row" data-row="row_2"></div>
                            <div class="row" data-row="row_3"></div>
                            <div class="row" data-row="row_4"></div>
                            <div class="row" data-row="row_5"></div>
                            <div class="row" data-row="row_6"></div>
                            <div class="row" data-row="row_7"></div>
                            <div class="row" data-row="row_8"></div>
                            <div class="row" data-row="row_9"></div>
                            <div class="row" data-row="row_10"></div>
                            <div class="row" data-row="row_11"></div>
                            <div class="row" data-row="row_12">Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet</div>
                            <div class="row" data-row="row_13"></div>
                            <div class="row" data-row="row_14"></div>
                            <div class="row" data-row="row_15">
                                <a href="img/img1.jpg" data-fancybox="gallery" class="image_overlay">
                                    <img src="img/img1.jpg" alt="">
                                </a>
                            </div>
                            <div class="row" data-row="row_16">
                                <button class="button top comment_open"><img src="img/comment_img.png" alt=""></button>
                                <p class="comment_text">
                                    Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamco.
                                </p>
                            </div>
                        </div>
                        <div class="column">
                            <div class="row" data-row="row_1">
                                <button class="button top change_name"><img src="img/comment_img.png" alt=""></button>
                                <a href="/statistics" class="button bottom statistics_open"><img src="img/statistics_img.png" alt=""></a> Устройство 2
                            </div>
                            <div class="row" data-row="row_2"></div>
                            <div class="row" data-row="row_3"></div>
                            <div class="row" data-row="row_4"></div>
                            <div class="row" data-row="row_5"></div>
                            <div class="row" data-row="row_6"></div>
                            <div class="row" data-row="row_7">Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet</div>
                            <div class="row" data-row="row_8"></div>
                            <div class="row" data-row="row_9"></div>
                            <div class="row" data-row="row_10"></div>
                            <div class="row" data-row="row_11"></div>
                            <div class="row" data-row="row_12"></div>
                            <div class="row" data-row="row_13"></div>
                            <div class="row" data-row="row_14"></div>
                            <div class="row" data-row="row_15">
                                <a href="img/img2.jpg" data-fancybox="gallery" class="image_overlay">
                                    <img src="img/img2.jpg" alt="">
                                </a>
                            </div>
                            <div class="row" data-row="row_16">
                                <button class="button top comment_open"><img src="img/comment_img.png" alt=""></button>
                                <p class="comment_text">
                                    Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamco.
                                </p>
                            </div>
                        </div>
                        <div class="column">
                            <div class="row" data-row="row_1">
                                <button class="button top change_name"><img src="img/comment_img.png" alt=""></button>
                                <a href="/statistics" class="button bottom statistics_open"><img src="img/statistics_img.png" alt=""></a> Устройство 3
                            </div>
                            <div class="row" data-row="row_2"></div>
                            <div class="row" data-row="row_3"></div>
                            <div class="row" data-row="row_4"></div>
                            <div class="row" data-row="row_5"></div>
                            <div class="row" data-row="row_6"></div>
                            <div class="row" data-row="row_7"></div>
                            <div class="row" data-row="row_8"></div>
                            <div class="row" data-row="row_9"></div>
                            <div class="row" data-row="row_10"></div>
                            <div class="row" data-row="row_11"></div>
                            <div class="row" data-row="row_12"></div>
                            <div class="row" data-row="row_13"></div>
                            <div class="row" data-row="row_14"></div>
                            <div class="row" data-row="row_15">
                                <a href="img/img3.jpg" data-fancybox="gallery" class="image_overlay">
                                    <img src="img/img3.jpg" alt="">
                                </a>
                            </div>
                            <div class="row" data-row="row_16">
                                <button class="button top comment_open"><img src="img/comment_img.png" alt=""></button>
                                <p class="comment_text">
                                    Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamco.
                                </p>
                            </div>
                        </div>
                        <div class="column">
                            <div class="row" data-row="row_1">
                                <button class="button top change_name"><img src="img/comment_img.png" alt=""></button>
                                <a href="/statistics" class="button bottom statistics_open"><img src="img/statistics_img.png" alt=""></a> Устройство 4
                            </div>
                            <div class="row" data-row="row_2"></div>
                            <div class="row" data-row="row_3"></div>
                            <div class="row" data-row="row_4"></div>
                            <div class="row" data-row="row_5"></div>
                            <div class="row" data-row="row_6"></div>
                            <div class="row" data-row="row_7"></div>
                            <div class="row" data-row="row_8"></div>
                            <div class="row" data-row="row_9"></div>
                            <div class="row" data-row="row_10"></div>
                            <div class="row" data-row="row_11"></div>
                            <div class="row" data-row="row_12"></div>
                            <div class="row" data-row="row_13"></div>
                            <div class="row" data-row="row_14"></div>
                            <div class="row" data-row="row_15">
                                <a href="img/img4.jpg" data-fancybox="gallery" class="image_overlay">
                                    <img src="img/img4.jpg" alt="">
                                </a>
                            </div>
                            <div class="row" data-row="row_16">
                                <button class="button top comment_open"><img src="img/comment_img.png" alt=""></button>
                                <p class="comment_text">
                                    Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamco.
                                </p>
                            </div>
                        </div>
                        <div class="column">
                            <div class="row" data-row="row_1">
                                <button class="button top change_name"><img src="img/comment_img.png" alt=""></button>
                                <a href="/statistics" class="button bottom statistics_open"><img src="img/statistics_img.png" alt=""></a> Устройство 5
                            </div>
                            <div class="row" data-row="row_2"></div>
                            <div class="row" data-row="row_3"></div>
                            <div class="row" data-row="row_4"></div>
                            <div class="row" data-row="row_5"></div>
                            <div class="row" data-row="row_6"></div>
                            <div class="row" data-row="row_7"></div>
                            <div class="row" data-row="row_8"></div>
                            <div class="row" data-row="row_9"></div>
                            <div class="row" data-row="row_10"></div>
                            <div class="row" data-row="row_11"></div>
                            <div class="row" data-row="row_12"></div>
                            <div class="row" data-row="row_13"></div>
                            <div class="row" data-row="row_14"></div>
                            <div class="row" data-row="row_15">
                                <a href="img/img1.jpg" data-fancybox="gallery" class="image_overlay">
                                    <img src="img/img1.jpg" alt="">
                                </a>
                            </div>
                            <div class="row" data-row="row_16">
                                <button class="button top comment_open"><img src="img/comment_img.png" alt=""></button>
                                <p class="comment_text">
                                    Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamco.
                                </p>
                            </div>
                        </div>
                        <div class="column">
                            <div class="row" data-row="row_1">
                                <button class="button top change_name"><img src="img/comment_img.png" alt=""></button>
                                <a href="/statistics" class="button bottom statistics_open"><img src="img/statistics_img.png" alt=""></a> Устройство 6
                            </div>
                            <div class="row" data-row="row_2"></div>
                            <div class="row" data-row="row_3"></div>
                            <div class="row" data-row="row_4"></div>
                            <div class="row" data-row="row_5"></div>
                            <div class="row" data-row="row_6"></div>
                            <div class="row" data-row="row_7"></div>
                            <div class="row" data-row="row_8"></div>
                            <div class="row" data-row="row_9"></div>
                            <div class="row" data-row="row_10"></div>
                            <div class="row" data-row="row_11"></div>
                            <div class="row" data-row="row_12"></div>
                            <div class="row" data-row="row_13"></div>
                            <div class="row" data-row="row_14"></div>
                            <div class="row" data-row="row_15">
                                <a href="img/img2.jpg" data-fancybox="gallery" class="image_overlay">
                                    <img src="img/img2.jpg" alt="">
                                </a>
                            </div>
                            <div class="row" data-row="row_16">
                                <button class="button top comment_open"><img src="img/comment_img.png" alt=""></button>
                                <p class="comment_text">
                                    Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamco.
                                </p>
                            </div>
                        </div>
                        <button class="arrow" id="slide_left"><img src="img/arrow_right.png" alt=""></button>
                    </div>
                </div>
            </div>
        </div>
    </section>

    <div class="modal" id="modal">
        <div class="close_modal"><img src="img/close_modal.png" alt=""></div>
        <div class="title"><span>Уровень PH</span></div>
        <form>
            <div class="modal_content">
                <div class="element">
                    <span>Показатель:</span>
                    <input type="text" name="Показатель" required>
                </div>
                <div class="element">
                    <span>Устройство:</span>
                    <div class="sort_select">
                        <div class="sort_option" data-custom="Device1">
                            <span class="text">Устройство 1</span>
                            <span class="arrow"><img src="img/select_button.png" alt=""></span>
                        </div>
                        <ul class="sort_options">
                            <li data-custom="Device1">Устройство 1</li>
                            <li data-custom="Device2">Устройство 2</li>
                            <li data-custom="Device3">Устройство 3</li>
                            <li data-custom="Device4">Устройство 4</li>
                            <li data-custom="Device4">Устройство 5</li>
                            <li data-custom="Device4">Устройство 6</li>
                        </ul>
                    </div>
                </div>
                <div class="element">
                    <input type="submit" class="add_table" value="Добавить">
                </div>
            </div>
        </form>
    </div>

    <div class="modal" id="modal_comment">
        <div class="close_modal"><img src="img/close_modal.png" alt=""></div>
        <div class="title"><span>Комментарий</span></div>
        <form>
            <div class="modal_content">
                <div class="element">
                    <textarea name="Комментарий" cols="30" rows="10" required placeholder="Введите комментарий"></textarea>
                </div>
                <input type="submit" class="add_table" value="Добавить">
            </div>
        </form>
    </div>

    <div class="modal" id="modal_change_name">
        <div class="close_modal"><img src="img/close_modal.png" alt=""></div>
        <div class="title"><span>Изменить название</span></div>
        <form>
            <div class="modal_content">
                <div class="element">
                    <input type="text" name="Название" required placeholder="Введите название">
                </div>
                <input type="submit" class="add_table" value="Добавить">
            </div>
        </form>
    </div>

    <div id="overlay"></div>
  </div>
</template>
